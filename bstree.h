// CS2211b 2025
// Assignment 5
// Murray Watt
// 251341261
// mwatt29
// March 21 2025

#ifndef BSTREE_H
#define BSTREE_H

#include "datatype.h"

typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;

typedef BStree_node** BStree;

// BST operations
BStree bstree_ini(void);  // Initialize BST
void bstree_insert(BStree bst, Key key, Data data);  // Insert key-data pair
Data bstree_search(BStree bst, Key key);  // Search for key
void bstree_traverse(BStree bst);  // In-order traversal
void bstree_free(BStree bst);  // Free BST memory

#endif
