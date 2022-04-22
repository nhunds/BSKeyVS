//
// Created by Daniel Nico Hunds on 07.04.22.
//

#include "sub.h"


int comm(int conn_fd, Hash_Table* h_t) {

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
        char* delim = " ";
        char* token = strtok(in, delim);
        if(strncmp(token, "exit", 4) == 0) {
            puts("STATUS: Client ended session");
            shutdown(conn_fd, SHUT_WR);
            return 1;
        }
        if(strncmp(token, "shutdown", 8) == 0) {
            puts("Server was shutdown by client");
            shutdown(conn_fd, SHUT_RDWR);
            return 0;
        }
        if(strncmp(token, "set", 3) == 0) {
            puts("Client wants to set Key-Value in Data Storage");
            char* key = strtok(NULL, delim);
            char* val = strtok(NULL, delim);
            // Check if Key and Value was given from Client
            if(key == NULL || val == NULL) {
                strcpy(out, "No Data for Key or Value was set\n");
                puts(out);
                send(conn_fd, out, MAX, 0);
            } else {
                int status = h_t->set(h_t, key_val_constructor(key, val));
                // Evaluate result of set-function
                switch (status) {
                    case 1: {
                        strcpy(out, "Key-Value was updated in Storage\n");
                        break;
                    }
                    case 0: {
                        strcpy(out, "Key-Value was set in Storage\n");
                        break;
                    }
                    case -2: {
                        strcpy(out, "ERROR: Can't set Key-Value in Storage, Hash-Map was full\n");
                        break;
                    }
                    case -1: {
                        strcpy(out, "ERROR: Can't set Key-Value in Storage, because no Storage could been allocated\n");
                        break;
                    }
                    default:
                        puts("ERROR: Unpredicted error");
                        exit(2);
                }
                printf("%s", out);
                send(conn_fd, out, MAX, 0);
            }
        }
    }
}