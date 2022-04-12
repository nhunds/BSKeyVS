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

Key hash(char* char_key){

    Key key = 0;
    for (; *char_key; char_key++) {
        key += (int)*char_key;
    }

    return key;

}

/*
 * Sets value of corresponding entry in hash table h_t to val of k_v.
 * Stores k_v as new entry and destruct k_v if no corresponding entry exists, but free storage.
 * RETURN:
 * Returns -1 if k_v is NULL
 * Returns -2 if hash table is full
 * Returns 0 if k_v is stored as new entry
 * Returns 1 if corresponding entry to k_v is found, val in hash table is updated and k_v is destructed
 */
int hash_table_set(Hash_Table* h_t, Key_Val* k_v) {

    // For bad k_v return -1
    if(k_v == NULL)
        return -1;

    // Generate hash key of key from k_v for hash table h_v
    Key key = hash(k_v->key);
    key %= h_t->size;

    // Start for-loop at generated hash key
    for (Key i = key; i < h_t->size; i++) {

        // Lock at index i, if NULL store k_v at index and return 0
        if(h_t->table[i] == NULL) {
            h_t->table[i] = k_v;
            return 0;
        }

        // Lock if key at index I is equal to key of k_v, if update val from at index I with val from k_v and return 2
        if(strcmp(h_t->table[i]->key, k_v->key) == 0) {
            h_t->table[i]->val = k_v->val;
            key_val_destructure(k_v);
            return 1;
        }

    }

    // For-loop till generated hash key
    for (Key i = 0; i < key; i++) {

        // Lock at index i, if NULL store k_v at index and return 0
        if(h_t->table[i] == NULL) {
            h_t->table[i] = k_v;
            return 0;
        }

        // Lock if key at index I is equal to key of k_v, if update val from at index I with val from k_v and return 2
        if(strcmp(h_t->table[i]->key, k_v->key) == 0) {
            h_t->table[i]->val = k_v->val;
            key_val_destructure(k_v);
            return 1;
        }

    }

    // Hash table is full
    return -2;


}

/*
 * Returns value of matching key-value pair for given char_key.
 * If no matching key-value pair is found it returns NULL
 * RETURN:
 * Returns val of key-value pair, if matching key-value pair is found
 * Returns NULL if no matching key-value pair is found
 */
char* hash_table_get(Hash_Table* h_t, char* char_key) {

    // For bad char_key
    if(*char_key == EOF)
        return NULL;

    // Generate hash key from char_key for hash table h_v
    Key key = hash(char_key);
    key %= h_t->size;

    // Start for-loop at hash key
    for (Key i = key; i < h_t->size; i++) {

        if(h_t->table[i] == NULL)
            return NULL;

        if(strcmp(h_t->table[i]->key, char_key) == 0)
            return h_t->table[i]->val;

    }

    // Run for-loop till hash key
    for (Key i = 0; i < key; i++) {

        if(h_t->table[i] == NULL)
            return NULL;

        if(strcmp(h_t->table[i]->key, char_key) == 0)
            return h_t->table[i]->val;

    }

    return NULL;

}

/*
 * Deletes entry with key matching char_key and returns 0.
 * If no matching entry exists returns -2.
 * If char_key is empty returns -1.
 * RETURNS:
 * Returns 0 if matching entry is deleted.
 * Returns -1 if char_key is empty.
 * Returns -2 if no matching entry exists.
 */
int hash_table_del(Hash_Table* h_t, char* char_key) {

    // For bad char_key return -1
    if(*char_key == EOF)
        return -1;

    for (size_t i = 0; i < h_t->size; i++) {

        if(strcmp(h_t->table[i]->key, char_key) == 0) {
            // Garbage collect multiple equal entry's
            for (size_t j = i; j < h_t->size; j++) {
                key_val_destructure(h_t->table[j]);
                h_t->table[j] = NULL;
            }
            return 0;
        }

    }

    // If no entry found no matching entry exist
    return -2;

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

    h_t->set = hash_table_set;
    h_t->get = hash_table_get;
    h_t->del = hash_table_del;

    return h_t;

}

void hash_table_destructor(Hash_Table* h_t) {

    if(h_t == NULL)
        return;

    // Free memory allocated for Entry's
    for (int i = 0; i < h_t->size; i++) {
        key_val_destructure(h_t->table[i]);
    }

    free(h_t->table);
    free(h_t);

}