// CS2211b 2025
// Assignment 5
// Murray Watt
// 251341261
// mwatt29
// March 21 2025

#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

// Initialize empty BST
BStree bstree_ini(void) {
    BStree bst = (BStree)malloc(sizeof(BStree_node*));
    *bst = NULL;
    return bst;
}

// Helper: Create new node
static BStree_node *new_node(Key key, Data data) {
    BStree_node *node = (BStree_node*)malloc(sizeof(BStree_node));
    node->key = key;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Helper: Recursive insert
static void insert_helper(BStree_node **node, Key key, Data data) {
    if (!*node) *node = new_node(key, data);
    else {
        int cmp = key_comp(key, (*node)->key);
        if (cmp < 0) insert_helper(&(*node)->left, key, data);
        else if (cmp > 0) insert_helper(&(*node)->right, key, data);
        else { key_free(key); data_free(data); }  // Duplicate: free unused pair
    }
}

// Insert key-data pair (ignores duplicates)
void bstree_insert(BStree bst, Key key, Data data) {
    insert_helper(bst, key, data);
}

// Search for key
Data bstree_search(BStree bst, Key key) {
    BStree_node *current = *bst;
    while (current) {
        int cmp = key_comp(key, current->key);
        if (cmp < 0) current = current->left;
        else if (cmp > 0) current = current->right;
        else return current->data;
    }
    return NULL;
}

// Helper: In-order traversal (prints formatted output)
static void traverse_helper(BStree_node *node) {
    if (!node) return;
    traverse_helper(node->left);
    key_print(node->key);    // Prints "skey1 skey2"
    data_print(node->data);  // Prints "   Occurrence"
    printf("\n");
    traverse_helper(node->right);
}

// Print BST in-order
void bstree_traverse(BStree bst) {
    traverse_helper(*bst);
}

// Helper: Recursive free
static void free_helper(BStree_node *node) {
    if (!node) return;
    free_helper(node->left);
    free_helper(node->right);
    key_free(node->key);
    data_free(node->data);
    free(node);
}

// Free BST memory
void bstree_free(BStree bst) {
    free_helper(*bst);
    free(bst);
}
