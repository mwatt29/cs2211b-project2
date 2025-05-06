// CS2211b 2025
// Assignment 5
// Murray Watt
// 251341261
// mwatt29
// March 21 2025

#ifndef DATATYPE_H
#define DATATYPE_H

typedef struct { char *skey1; char *skey2; } Key_struct;
typedef Key_struct* Key;
typedef int* Data;

// Key operations
Key key_ini();  // Initialize key
void key_set(Key key, char *skey1, char *skey2);  // Set key values
int key_comp(Key key1, Key key2);  // Compare keys
void key_print(Key key);  // Print key (formatted)
void key_free(Key key);  // Free key memory
char *string_dup(char *str);  // Duplicate string

// Data operations
Data data_ini();  // Initialize data
void data_set(Data data, int intdata);  // Set data value
void data_print(Data data);  // Print data (formatted)
void data_free(Data data);  // Free data memory

#endif
