CC = gcc
CFLAGS = -Wall -pedantic -std=c99
INCLUDES = -Iinclude
BINDIR = bin/
SRCDIR = src/
SOURCE = $(SRCDIR)linkedlist.c $(SRCDIR)stack.c $(SRCDIR)maze.c $(SRCDIR)
PROGNAME = $(BINDIR)runSolver

all:
	$(CC) $(CFLAG) $(SOURCE) $(SRCDIR)main.c $(INCLUDES) -o $(PROGNAME)

test:	
	$(CC) $(CFLAG) $(SOURCE) $(SRCDIR)testMain.c $(INCLUDES) -o $(BINDIR)runTest
