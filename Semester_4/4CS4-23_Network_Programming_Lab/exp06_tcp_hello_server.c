/* Exp 6: TCP Hello Server */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(void) {
    int srv = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    bind(srv, (struct sockaddr *)&addr, sizeof(addr));
    listen(srv, 5);
    printf("TCP Hello Server listening on port 8080...\n");

    int cli = accept(srv, NULL, NULL);
    char buf[256] = {0};
    ssize_t n = read(cli, buf, sizeof(buf) - 1);
    if (n > 0) printf("Received from client: %s\n", buf);
    close(cli);
    close(srv);
    return 0;
}
