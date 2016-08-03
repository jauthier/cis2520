CC = gcc
CFLAGS = -Wall -pedantic -std=c99

all:
	$(CC) $(CFLAGS) -Iinclude -c -o bin/main.o src/main.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurant.o src/restaurant.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurantFunctions.o src/restaurantFunctions.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/linkedlist.o src/linkedlist.c
	$(CC) -Llib bin/main.o bin/restaurant.o bin/restaurantFunctions.o bin/linkedlist.o -lbintree -o bin/run

restaurantTest:
	$(CC) $(CFLAGS) -Iinclude -c -o bin/testRestADT.o src/testRestADT.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurant.o src/restaurant.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurantFunctions.o src/restaurantFunctions.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/linkedlist.o src/linkedlist.c
	$(CC) -Llib bin/testRestADT.o bin/restaurant.o bin/restaurantFunctions.o bin/linkedlist.o -lbintree -o bin/runTestRest	

fileTest:
	$(CC) $(CFLAGS) -Iinclude -c -o bin/testFileIn.o src/testFileIn.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurant.o src/restaurant.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurantFunctions.o src/restaurantFunctions.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/linkedlist.o src/linkedlist.c
	$(CC) -Llib bin/testFileIn.o bin/restaurant.o bin/linkedlist.o bin/restaurantFunctions.o -lbintree -o bin/runFileTest
	
binTreeTest:
	$(CC) $(CFLAGS) -Iinclude -c -o bin/testBinTree.o src/testBinTree.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurant.o src/restaurant.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurantFunctions.o src/restaurantFunctions.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/linkedlist.o src/linkedlist.c
	$(CC) -Llib bin/testBinTree.o bin/restaurant.o bin/restaurantFunctions.o bin/linkedlist.o -lbintree -o bin/runTestTree
	
