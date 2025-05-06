// CS2211b 2025
// Assignment 5
// Murray Watt
// 251341261
// mwatt29
// March 21 2025

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
    Matrix m = matrix_construction();  // Initialize matrix
    char str1[100], str2[100];

    // Read pairs until EOF (Ctrl+D or end of file)
    while (scanf("%99s %99s", str1, str2) == 2) {
        if (matrix_index_in(m, str1, str2)) {
            // Increment existing count
            int val = matrix_get(m, str1, str2);
            matrix_set(m, str1, str2, val + 1);
        } else {
            // Insert new pair with count=1
            matrix_set(m, str1, str2, 1);
        }
    }

    matrix_list(m);  // Print formatted output
    matrix_destruction(m);  // Free memory
    return 0;
}
