//
// Created by Daniel Nico Hunds on 07.04.22.
//

#include "keyValStore.h"

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