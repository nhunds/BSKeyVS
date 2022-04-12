//
// Created by Daniel Nico Hunds on 07.04.22.
//

#include "main.h"

int main() {

    Hash_Table* h_t = hash_table_constructor(20);

    h_t->set(h_t, key_val_constructor("Test_0", "Data_0"));
    h_t->set(h_t, key_val_constructor("Test_1", "Data_1"));
    h_t->set(h_t, key_val_constructor("Test_2", "Data_2"));
    h_t->set(h_t, key_val_constructor("Test_3", "Data_3"));
    h_t->set(h_t, key_val_constructor("Test_4", "Data_4"));

    h_t->del(h_t, "Test_0");
    h_t->set(h_t, key_val_constructor("Test_5", "Data_5"));

    printf("%s\n", h_t->get(h_t, "Test_5"));
    printf("%s\n", h_t->get(h_t, "Test_1"));
    printf("%s\n", h_t->get(h_t, "Test_2"));
    printf("%s\n", h_t->get(h_t, "Test_3"));
    printf("%s\n", h_t->get(h_t, "Test_4"));

    hash_table_destructor(h_t);


/*    h_t->set(h_t, key_val_constructor("Test_0", "Hallo_0"));
    h_t->set(h_t, key_val_constructor("Test_1", "Hallo_1"));
    h_t->set(h_t, key_val_constructor("Test_2", "Hallo_2"));
    h_t->set(h_t, key_val_constructor("Test_3", "Hallo_3"));
    h_t->set(h_t, key_val_constructor("Test_4", "Hallo_4"));

    for(int i = 0; i < 5; i++)
        printf("%s\n", h_t->table[i]->val);

    hash_table_destructor(h_t);*/

/*    int serv_fd, conn_fd, serv_run;
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

    shutdown(serv_fd, SHUT_RDWR);*/

    exit(0);
}
