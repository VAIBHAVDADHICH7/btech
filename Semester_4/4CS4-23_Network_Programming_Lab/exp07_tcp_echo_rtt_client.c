/* Exp 7: TCP Echo Client with RTT Estimation */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8081);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) { perror("connect"); return 1; }

    struct timeval t1, t2;
    const char *msg = "RTT_PROBE";
    char buf[128] = {0};

    gettimeofday(&t1, NULL);
    write(sock, msg, strlen(msg));
    read(sock, buf, sizeof(buf) - 1);
    gettimeofday(&t2, NULL);

    double rtt_ms = (t2.tv_sec - t1.tv_sec) * 1000.0 + (t2.tv_usec - t1.tv_usec) / 1000.0;
    printf("Echoed: %s | RTT: %.3f ms\n", buf, rtt_ms);
    close(sock);
    return 0;
}
