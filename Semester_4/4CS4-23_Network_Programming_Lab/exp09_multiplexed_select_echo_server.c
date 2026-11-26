/* Exp 9: Multiplexed I/O TCP Echo Server using select() */
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <arpa/inet.h>

int main(void) {
    int srv = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8083);
    bind(srv, (struct sockaddr *)&addr, sizeof(addr));
    listen(srv, 10);

    fd_set master, readfds;
    FD_ZERO(&master);
    FD_SET(srv, &master);
    int fdmax = srv;
    printf("Multiplexed select() Echo Server on port 8083...\n");

    while (1) {
        readfds = master;
        select(fdmax + 1, &readfds, NULL, NULL, NULL);
        for (int fd = 0; fd <= fdmax; fd++) {
            if (!FD_ISSET(fd, &readfds)) continue;
            if (fd == srv) {
                int cli = accept(srv, NULL, NULL);
                FD_SET(cli, &master);
                if (cli > fdmax) fdmax = cli;
            } else {
                char buf[512];
                ssize_t n = read(fd, buf, sizeof(buf));
                if (n <= 0) { close(fd); FD_CLR(fd, &master); }
                else write(fd, buf, (size_t)n);
            }
        }
    }
    return 0;
}
