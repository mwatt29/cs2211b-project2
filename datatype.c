// CS2211b 2025
// Assignment 5
// Murray Watt
// 251341261
// mwatt29
// March 23 2025
#include "datatype.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creates and initializes a new key structure
Key key_ini() {
    Key key = (Key)malloc(sizeof(Key_struct));
    key->skey1 = NULL;
    key->skey2 = NULL;
    return key;
}

// Sets key values by duplicating the input strings
void key_set(Key key, char *skey1, char *skey2) {
    key->skey1 = string_dup(skey1);  // Duplicate first string
    key->skey2 = string_dup(skey2);  // Duplicate second string
}

// Compares two keys alphabetically
int key_comp(Key key1, Key key2) {
    // First compare the first strings
    int cmp = strcmp(key1->skey1, key2->skey1);
    // If equal, compare the second strings
    return cmp != 0 ? cmp : strcmp(key1->skey2, key2->skey2);
}

// Prints key in two fixed-width columns
void key_print(Key key) {
    printf("%-10s %-10s", key->skey1, key->skey2);  // Left-aligned
}

// Frees memory used by a key
void key_free(Key key) {
    free(key->skey1);  // Free first string
    free(key->skey2);  // Free second string
    free(key);         // Free key structure
}

// Helper function to duplicate a string
char *string_dup(char *str) {
    if (!str) return NULL;
    char *dup = malloc(strlen(str) + 1);  // Allocate memory
    if (dup) strcpy(dup, str);            // Copy string
    return dup;
}

// Creates and initializes a new data structure
Data data_ini() {
    Data data = (Data)malloc(sizeof(int));  // Allocate memory for int
    *data = 0;                              // Initialize to 0
    return data;
}

// Sets the value of data
void data_set(Data data, int intdata) {
    *data = intdata;  // Assign value
}

// Prints data in a fixed-width column
void data_print(Data data) {
    printf("%10d", *data);  // Right-aligned
}

// Frees memory used by data
void data_free(Data data) {
    free(data);  // Free the integer
}
