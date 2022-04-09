//
// Created by Daniel Nico Hunds on 07.04.22.
//

#include "sub.h"


int comm(int conn_fd) {

    char in[MAX], out[MAX];

    for(;;) {
        bzero(in, MAX);
        bzero(out, MAX);

        // Send ">>"-Prompt to client
        strcpy(out, ">> ");
        if(send(conn_fd, out, MAX, 0) == -1) {
            perror("ERROR: Can't send massage to client");
            exit(2);
        }

        // Receive command from client
        if(recv(conn_fd, in, MAX, 0) == -1) {
            perror("ERROR: Can't receive massage from client");
            exit(2);
        }
        // Command to lower case
        for(int i = 0; in[i]; i++)
            in[i] = tolower(in[i]);
        printf("STATUS: Client send: %s", in);

        // Interpret command from client
        if(strncmp(in, "exit", 4) == 0) {
            puts("STATUS: Client ended session");
            shutdown(conn_fd, SHUT_WR);
            return 1;
        }
        if(strncmp(in, "shutdown", 8) == 0) {
            puts("Server was shutdown by client");
            shutdown(conn_fd, SHUT_RDWR);
            return 0;
        }
    }
}