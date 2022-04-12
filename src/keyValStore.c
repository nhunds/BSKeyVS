//
// Created by Daniel Nico Hunds on 07.04.22.
//

#include "keyValStore.h"

Key_Val* key_val_constructor(char* key, char* val) {

    Key_Val* k_v = malloc(sizeof(Key_Val));

    k_v->key = key;
    k_v->val = val;

}