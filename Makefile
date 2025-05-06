# CS2211b 2025
# Assignment 5
# Murray Watt
# 251341261
# mwatt29
# March 23 2025

# Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c11 -g  # Enable warnings

# Target executable
TARGET = mymatrix

# Object files
OBJS = main.o datatype.o bstree.o matrix.o

# Default target (run when you type 'make')
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c file into a .o file
main.o: main.c matrix.h
	$(CC) $(CFLAGS) -c main.c

datatype.o: datatype.c datatype.h
	$(CC) $(CFLAGS) -c datatype.c

bstree.o: bstree.c bstree.h datatype.h
	$(CC) $(CFLAGS) -c bstree.c

matrix.o: matrix.c matrix.h bstree.h
	$(CC) $(CFLAGS) -c matrix.c

# Clean up object files and executable
clean:
	rm -f $(TARGET) $(OBJS)
