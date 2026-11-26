/* Exp 7: Concurrent TCP Echo Server (fork per connection) */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>

int main(void) {
    signal(SIGCHLD, SIG_IGN);
    int srv = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8081);

    bind(srv, (struct sockaddr *)&addr, sizeof(addr));
    listen(srv, 10);
    printf("Concurrent TCP Echo Server on port 8081...\n");

    while (1) {
        int cli = accept(srv, NULL, NULL);
        if (fork() == 0) {
            close(srv);
            char buf[512];
            ssize_t n;
            while ((n = read(cli, buf, sizeof(buf))) > 0) write(cli, buf, (size_t)n);
            close(cli);
            return 0;
        }
        close(cli);
    }
}
