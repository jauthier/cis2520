CC = gcc
CFLAGS = -Wall -pedantic -std=c99

all:
	$(CC) $(CFLAGS) -Iinclude -c -o bin/main.o src/main.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurant.o src/restaurant.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurantFunctions.o src/restaurantFunctions.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/linkedlist.o src/linkedlist.c
	$(CC) -Llib bin/main.o bin/restaurant.o bin/restaurantFunctions.o bin/linkedlist.o -lbintree -o bin/run

restaurantTest:
	$(CC) $(CFLAGS) src/testRestADT.c src/restaurant.c -Iinclude src/restaurantFunctions.c -o bin/runTestRest	

fileTest:
	$(CC) $(CFLAGS) src/testFileIn.c src/restaurant.c src/linkedlist.c src/restaurantFunctions.c -Iinclude -o bin/runFileTest
	
binTreeTest:
	$(CC) $(CFLAGS) -Iinclude -c -o bin/testBinTree.o src/testBinTree.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurant.o src/restaurant.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/restaurantFunctions.o src/restaurantFunctions.c
	$(CC) $(CFLAGS) -Iinclude -c -o bin/linkedlist.o src/linkedlist.c
	$(CC) -Llib bin/testBinTree.o bin/restaurant.o bin/restaurantFunctions.o bin/linkedlist.o -lbintree -o bin/runTestTree
	
