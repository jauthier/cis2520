CC = gcc
CFLAGS = -Wall -pedantic -std=c99
INCLUDES = -Iinclude
BINDIR = bin/
SOURCE = src/main.c src/linkedlist.c src/initalize.c src/hashtable.c src/mergeSort.c

all:
	$(CC) $(CFLAGS) $(SOURCE) $(INCLUDES) -o run

testHT:
	$(CC) $(CFLAGS) src/hashtable.c src/testHT.c $(INCLUDES) -o runHTTest
