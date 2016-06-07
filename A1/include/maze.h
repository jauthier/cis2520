
#include <stdio.h>
#include <stdlib.h>

typedef struct Square{
    
    char val; // the char the square contains
    int wall; // is this square a wall
    int x; // x coordinate
    int y; // y coordinate
    int wasHere; //have we been here before
    
} Square;


void parseFile(char * fileName);
Square * createSquare(char v, int x, int y);
void printMaze();

/*
    either use left had or right hand rule
    only turning left of right.  
    char dir; //direction, n = north, s = south, e = east, w = west

*/


