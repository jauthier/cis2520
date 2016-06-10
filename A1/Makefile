CC = gcc
CFLAGS = -Wall -pedantic -std=c99
INCLUDES = -Iinclude
BINDIR = bin/
SRCDIR = src/
SOURCE = $(SRCDIR)linkedlist.c $(SRCDIR)stack.c $(SRCDIR)maze.c
PROGNAME = $(BINDIR)runSolver

all:
	$(CC) $(CFLAG) $(SOURCE) src/main.c $(INCLUDES) -o $(PROGNAME)

mazeTest:	
	$(CC) $(CFLAG) $(SOURCE) src/mazeTest.c $(INCLUDES) -o bin/mazeTestRun

stackTest:
	$(CC) $(CFLAG) src/linkedlist.c src/stack.c src/stackTest.c $(INCLUDES) -o bin/stackRun

listTest:
	$(CC) $(CFLAG) src/linkedlist.c src/listTest.c $(INCLUDES) -o bin/listRun
