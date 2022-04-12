//
// Created by Daniel Nico Hunds on 07.04.22.
//

#include "keyValStore.h"

// Type vor Hash-Key's
typedef unsigned int Key;

Key_Val* key_val_constructor(char* key, char* val) {

    Key_Val* k_v = malloc(sizeof(Key_Val));

    k_v->key = key;
    k_v->val = val;

    return k_v;

}

void key_val_destructure(Key_Val* k_v) {
    free(k_v);
}

Hash_Table* hash_table_constructor(size_t size) {

    Hash_Table* h_t = malloc(sizeof(Hash_Table));
    if(h_t == NULL) {
        return NULL;
    }

    h_t->table = calloc(size, sizeof(Key_Val*));
    if(h_t->table == NULL) {
        free(h_t);
        return NULL;
    }
    h_t->size = size;

    return h_t;

}

void hash_table_destructor(Hash_Table* h_t) {

    if(h_t == NULL)
        return;

    // Free memory allocated for Entry's
    for (int i = 0; i < h_t->size; i++) {
        key_val_destructure(h_t->table[i]);
    }

    free(h_t);

}