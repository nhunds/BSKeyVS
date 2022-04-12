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
void key_val_destructure(Key_Val* k_v);

typedef struct Hash_Table {
    Key_Val** table;
    size_t size;
} Hash_Table;

Hash_Table* hash_table_constructor(size_t size);
void hash_table_destructor(Hash_Table* h_t);

#endif //BSKEYVS_KEYVALSTORE_H
