// CS2211b 2025
// Assignment 5
// Murray Watt
// 251341261
// mwatt29
// March 21 2025

#ifndef MATRIX_H
#define MATRIX_H

#include "bstree.h"

typedef BStree Matrix;
typedef char* Index;
typedef int Value;

// Matrix operations
Matrix matrix_construction(void);  // Initialize matrix
unsigned char matrix_index_in(Matrix m, Index index1, Index index2);  // Check if index exists
Value matrix_get(Matrix m, Index index1, Index index2);  // Get value at index
void matrix_set(Matrix m, Index index1, Index index2, Value value);  // Set value at index
void matrix_list(Matrix m);  // Print matrix (formatted)
void matrix_destruction(Matrix m);  // Free matrix memory

#endif
