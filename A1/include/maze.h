
#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "linkedlist.h"

typedef struct Square{
    
    char val; // the char the square contains
    int wall; // is this square a wall
    int x; // x coordinate
    int y; // y coordinate
    int wasHere; //have we been here before
    
} Square;

/*
    Purpose: to take a text file of the appropriate format and translate it into
    an m x n matrix of Square pointers
    Preconditions: a text file of the appropriate format
    Postconditions: the information from the file is put into the m x n matrix 
*/
void parseFile(char * fileName);

/*
    Purpose: to allocate memory and initialize a Square variable
    Preconditions: the value of the square and the x and y coordinates
    Postconditions: a Square variable is set and its components are set to the
    values passed as parameters
*/
Square * createSquare(char v, int x, int y);

/*
    Purpose: to print the maze to the screen
    Preconditions: an initialized maze[][] variable
    Postconditions: display the maze on the screen
*/
void printMaze();

/*
    Purpose: Checks if the the space above is occupied by a wall, returns 0 if it is
    and 1 if it isn't
    Preconditions: an initialized maze[][] variable
    Postconditions: none
*/
int checkUp();

/*
    Purpose: Checks if the the space below is occupied by a wall, returns 0 if it is
    and 1 if it isn't
    Preconditions: an initialized maze[][] variable
    Postconditions: none
*/
int checkDown();

/*
    Purpose: Checks if the the space to the right is occupied by a wall, returns 0 if it is
    and 1 if it isn't
    Preconditions: an initialized maze[][] variable
    Postconditions: none
*/
int checkRight();

/*
    Purpose: Checks if the the space tot he left is occupied by a wall, returns 0 if it is
    and 1 if it isn't
    Preconditions: an initialized maze[][] variable
    Postconditions: none
*/
int checkLeft();

void changeDir();

void navigate();


#endif