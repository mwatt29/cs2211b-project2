// CS2211b 2025
// Assignment 5
// Murray Watt
// 251341261
// mwatt29
// March 21 2025

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

// Initialize matrix (uses BST)
Matrix matrix_construction(void) {
    return bstree_ini();
}

// Check if index exists in matrix
unsigned char matrix_index_in(Matrix m, Index index1, Index index2) {
    Key key = key_ini();
    key_set(key, index1, index2);
    Data data = bstree_search(m, key);
    key_free(key);
    return data != NULL;
}

// Get value at index (returns -1 if not found)
Value matrix_get(Matrix m, Index index1, Index index2) {
    Key key = key_ini();
    key_set(key, index1, index2);
    Data data = bstree_search(m, key);
    key_free(key);
    return data ? *data : -1;
}

// Set value at index (overwrites if exists)
void matrix_set(Matrix m, Index index1, Index index2, Value value) {
    Key key = key_ini();
    key_set(key, index1, index2);
    Data data = bstree_search(m, key);
    if (data) { *data = value; key_free(key); }  // Overwrite
    else { Data new_data = data_ini(); *new_data = value; bstree_insert(m, key, new_data); }  // Insert new
}

// Print matrix with aligned columns
void matrix_list(Matrix m) {
    printf("%-10s %-10s %10s\n", "String 1", "String 2", "Occurrence");  // Header
    bstree_traverse(m);  // Formatted output
}

// Free matrix memory
void matrix_destruction(Matrix m) {
    bstree_free(m);
}
