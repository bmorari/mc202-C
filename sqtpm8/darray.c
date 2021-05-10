#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "darray.h"

darray* da_alloc(int capacity){
    return malloc(capacity);
}

int da_push(darray* A, char* string) {
    for (int i = 0; i < A->capacity; i++) {
        if (!A->data[i]) {
            int len_string = strlen(string) + 1;
            A->data[i] = (char*)malloc(len_string * sizeof(char));
            strcpy(A->data[i], string);
            return 1;
        }
    }
    return 0;
}

char* da_pop(darray* A) {
    ;
}

int da_inject(darray* A, char* string) {
    ;
}

char* da_eject(darray* A) {
    ;
}

char* da_first(darray* A){
    ;
}

char* da_last(darray* A){
    ;
}

int da_is_empty(darray* A){
    for (int i = 0; i < A->capacity; i++) {
        if (A->data[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

void da_free(darray* A){
    ;
}
