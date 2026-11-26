/* Exp 8: UDP Echo Client with RTT Measurement */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>

int main(void) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in srv = {0};
    srv.sin_family = AF_INET;
    srv.sin_port = htons(8082);
    inet_pton(AF_INET, "127.0.0.1", &srv.sin_addr);

    struct timeval t1, t2;
    const char *msg = "Hello UDP!";
    char buf[128] = {0};
    socklen_t len = sizeof(srv);

    gettimeofday(&t1, NULL);
    sendto(sock, msg, strlen(msg), 0, (struct sockaddr *)&srv, len);
    recvfrom(sock, buf, sizeof(buf) - 1, 0, NULL, NULL);
    gettimeofday(&t2, NULL);

    double rtt_ms = (t2.tv_sec - t1.tv_sec) * 1000.0 + (t2.tv_usec - t1.tv_usec) / 1000.0;
    printf("UDP Echo: %s | RTT: %.3f ms\n", buf, rtt_ms);
    close(sock);
    return 0;
}
