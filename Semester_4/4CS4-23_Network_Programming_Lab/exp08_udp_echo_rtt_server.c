/* Exp 8: UDP Echo Server */
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(void) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in srv = {0}, cli;
    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = INADDR_ANY;
    srv.sin_port = htons(8082);

    bind(sock, (struct sockaddr *)&srv, sizeof(srv));
    printf("UDP Echo Server on port 8082...\n");

    char buf[512];
    socklen_t len = sizeof(cli);
    while (1) {
        ssize_t n = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&cli, &len);
        if (n > 0) sendto(sock, buf, (size_t)n, 0, (struct sockaddr *)&cli, len);
    }
    close(sock);
    return 0;
}
