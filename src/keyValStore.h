//
// Created by Daniel Nico Hunds on 07.04.22.
//

#ifndef BSKEYVS_KEYVALSTORE_H
#define BSKEYVS_KEYVALSTORE_H
#include "main.h"

typedef struct Key_Val {
    char* key;
    char* val;
} Key_Val;

Key_Val* key_val_constructor(char* key, char* val);

#endif //BSKEYVS_KEYVALSTORE_H
