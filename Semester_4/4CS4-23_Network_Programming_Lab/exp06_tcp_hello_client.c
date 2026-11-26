/* Exp 6: TCP Hello Client */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        const char *msg = "Hello, world!";
        write(sock, msg, strlen(msg));
        printf("Sent: %s\n", msg);
    } else perror("connect");
    close(sock);
    return 0;
}
