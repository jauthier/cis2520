CC = gcc
CFLAGS = -Wall -pedantic -std=c99

all:
	$(CC) $(CFLAGS) -Iinclude -c -o bin/main.o src/main.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurant.o src/restaurant.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurantFunctions.o src/restaurantFunctions.c
	$(CC) -Llib bin/main.o bin/restaurant.o bin/restaurantFunctions. -lbintree -o bin/runTest

restaurantTest:
	$(CC) $(CFLAGS) src/testRestADT.c src/restaurant.c -Iinclude -o bin/runTestRest	

fileTest:
	$(CC) $(CFLAGS) src/testFileIn.c src/restaurant.c src/linkedlist.c -Iinclude -o bin/runFileTest
	
binTreeTest:
	$(CC) $(CFLAGS) -Iinclude -c -o bin/testBinTree.o src/testBinTree.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurant.o src/restaurant.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurantFunctions.o src/restaurantFunctions.c
	$(CC) -Llib bin/testBinTree.o bin/restaurant.o -lbintree -o bin/runTestTree
	
