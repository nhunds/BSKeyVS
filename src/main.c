//
// Created by Daniel Nico Hunds on 07.04.22.
//

#include "main.h"

int main() {

    int serv_fd, conn_fd, serv_run;
    struct sockaddr_in server, client;
    int cli_len = sizeof(client);

    // Create stream socket
    serv_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(serv_fd < 0) {
        perror("ERROR: Can't create stream socket");
        exit(2);
    }
    puts("STATUS: Stream socket created");

    // Configure server
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind server to socket
    if(bind(serv_fd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("ERROR: Can't bind server address to stream socket");
        exit(2);
    }
    puts("STATUS: Server address bound to stream socket");

    if(listen(serv_fd, 5) < 0) {
        perror("ERROR: Server not listening");
        exit(2);
    }
    puts("STATUS: Server is listening");

    serv_run = 1;
    while(serv_run) {
        // Accept connection from client to server
        conn_fd = accept(serv_fd, (struct sockaddr *) &client, (socklen_t *) &cli_len);
        if(conn_fd == -1) {
            perror("ERROR: Can't establish connection");
            exit(2);
        }
        printf("STATUS: Connection established");

        serv_run = comm(conn_fd);
    }

    shutdown(serv_fd, SHUT_RDWR);

    return 0;
}
