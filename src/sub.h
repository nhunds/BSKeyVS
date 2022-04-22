//
// Created by Daniel Nico Hunds on 07.04.22.
//

#ifndef BSKEYVS_SUB_H
#define BSKEYVS_SUB_H

#include "main.h"

// Communicate with explicit Client over connfd. Return 0 if Server shutdown.
int comm(int conn_fd, Hash_Table* h_t);

#endif //BSKEYVS_SUB_H
