CC = gcc
CFLAGS = -Wall -pedantic -std=c99



all:
	$(CC) $(CFLAGS) -Iinclude -c -o testRestADT.o src/testRestADT.c
	$(CC) $(CFLAGS) -Iinclude -c -o restaurant.o src/restaurant.c
	$(CC) -Llib testRestADT.o restaurant.o -lbintree -o runTest

restaurantTest:
	$(CC) $(CFLAGS) src/testRestADT.c src/restaurant.c -Iinclude -o runTestRest	

fileTest:
	$(CC) $(CFLAGS) src/testFileIn.c src/restaurant.c src/linkedlist.c -Iinclude -o runFileTest
	
binTreeTest:
	$(CC) $(CFLAGS) -Iinclude -c -o testBinTree.o src/testBinTree.c
	$(CC) $(CFLAGS) -Iinclude -c -o restaurant.o src/restaurant.c
	$(CC) -Llib testBinTree.o restaurant.o -lbintree -o runTestTree
	
