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

    /*
     * Sets value of corresponding entry in hash table h_t to val of k_v.
     * Stores k_v as new entry and destruct k_v if no corresponding entry exists, but free storage.
     * RETURN:
     * Returns -1 if k_v is NULL
     * Returns -2 if hash table is full
     * Returns 0 if k_v is stored as new entry
     * Returns 1 if corresponding entry to k_v is found, val in hash table is updated and k_v is destructed
     */
    int (*set)(struct Hash_Table*, Key_Val*);
    /*
     * Returns value of matching key-value pair for given char_key.
     * If no matching key-value pair is found it returns NULL
     * RETURN:
     * Returns val of key-value pair, if matching key-value pair is found
     * Returns NULL if no matching key-value pair is found
     */
    char* (*get)(struct Hash_Table*, char*);
    /*
     * Deletes entry with key matching char_key and returns 0.
     * If no matching entry exists returns -2.
     * If char_key is empty returns -1.
     * RETURNS:
     * Returns 0 if matching entry is deleted.
     * Returns -1 if char_key is empty.
     * Returns -2 if no matching entry exists.
     */
    int (*del)(struct Hash_Table*, char*);
} Hash_Table;

Hash_Table* hash_table_constructor(size_t size);
void hash_table_destructor(Hash_Table* h_t);

#endif //BSKEYVS_KEYVALSTORE_H
