# cs2211b-project2

# What This Project Does

# Overview
This assignment involves implementing an associative matrix (a 2D array indexed by string pairs) using Binary Search Trees (BSTs) in C. The matrix will track occurrences of string pairs dynamically, with proper memory management and recursive BST operations.

Files Structure:

datatype.h	Defines Key, Data types and function prototypes.
datatype.c	Implements Key and Data operations (construction, comparison, memory management).
bstree.h	Defines BST node structure (BStree_node) and BST operations.
bstree.c	Implements BST functions (insertion, search, traversal, memory deallocation).
matrix.h	Defines Matrix (as a BST) and matrix operations.
matrix.c	Implements matrix functions (lookup, insertion, printing).
main.c	Reads input, builds the matrix, prints results, and cleans up.
Makefile	Compiles the project into mymatrix.
Data Structures
1. Key and Data
Key: A pair of strings (char* skey1, char* skey2).

Functions:

key_ini(): Allocates and initializes a Key.

key_set(): Copies strings into a Key.

key_comp(): Compares two keys (uses strcmp).

key_print(): Prints the key.

key_free(): Frees memory.

Data: A pointer to an integer (int*).

Functions:

data_ini(): Allocates and initializes Data.

data_set(): Assigns an integer value.

data_print(): Prints the data.

data_free(): Frees memory.

2. Binary Search Tree (BST)
BStree_node:


typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;
Operations:

bstree_ini(): Initializes an empty BST.

bstree_insert(): Inserts a key-data pair (no duplicates).

bstree_search(): Returns data for a given key.

bstree_traverse(): In-order traversal (prints sorted keys).

bstree_free(): Recursively frees the BST.

3. Matrix (BST-Based Associative Array)
Matrix: A BST where each node’s key is a pair of strings (Index = char*), and the data is an integer (Value = int).

Operations:

matrix_construction(): Initializes the matrix.

matrix_index_in(): Checks if a string pair exists.

matrix_get(): Returns the count for a string pair.

matrix_set(): Inserts/updates a string pair’s count.

matrix_list(): Prints all entries (sorted).

matrix_destruction(): Frees the matrix.

Implementation Notes
Key Functions
String Comparison:


int key_comp(Key key1, Key key2) {
    int cmp = strcmp(key1->skey1, key2->skey1);
    return (cmp != 0) ? cmp : strcmp(key1->skey2, key2->skey2);
}
Memory Management:

Use string_dup() to copy strings dynamically.

Always free keys/data when deleting nodes.

BST Operations
Recursive Insertion/Traversal:

Insertion must maintain BST order (left < root < right).

Traversal prints in ascending order.

Matrix Workflow
Input Handling:

Read string pairs (e.g., "bba aa") from stdin or a file.

Use scanf("%s %s", str1, str2) and check for EOF.

Counting Occurrences:

For each pair, increment its count in the matrix.

Output:

Print in format:

String1    String2    Occurrence
bba        aa         2
aab        abb        1
Compilation & Execution
1. Compile with Makefile

make        ,Compiles to 'mymatrix'
make clean  ,Removes generated files
2. Run the Program

./mymatrix < input.txt   ,Redirect input from file
./mymatrix              ,Manual input (Ctrl+D to end)
Sample Input/Output
Input (input.txt):

bba aa  
aab aab  
bba aa  
aab abb  
bba aaa  
Output:

String1    String2    Occurrence  
aab        aab        1  
aab        abb        1  
bba        aa         2  
bba        aaa        1  
