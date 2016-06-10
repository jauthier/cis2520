/*
    Author: Jessica Authier
    2016/06/10
*/

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
    int deadEnd; //is this square part of a deadEnd
    
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
    Purpose: to get the starting direction, it will be the direction pointing away
    from the wall (n = north, pointing up   s = south, pointing down  
    e = east, pointing to the right   w = west, pointing to the left)
    Preconditions: an initialized maze and starting location
    Postconditions: the global variable dir is set to the direction char
*/
void initDir();

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

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
void changeDir();

/*
    Purpose: to change the values of the squares that create the solution to the maze, so it 
    can be viewed when the maze is printed
    Preconditions: an initialized, non-empty stack 
    Postconditions: the values of the squares in the stack are changed to '.'
*/
void setPath();

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
int otherOptions(int nextX, int nextY);

/*
    Purpose: check to see if the next square is a wall or not, calls one of: checkUp, checkDown, 
    checkRight or checkLeft, depending on the current direction
    Preconditions: initialized maze and a current direction
    Postconditions: none
*/
void navigate();

#endif