
#include "maze.h"
#include <stdio.h>
#include <stdlib.h>

Square * current;
Square * start;
Square * finish;

void parseFile(char * fileName);
Square * createSquare(char v, int x, int y);

int main(int argc, char * argv[]){
    
    char * fileName;
    
    if (argc != 2){
        printf("Incorrect input\n");
        exit(0);
    }
    
    fileName = argv[1];
    
    parseFile(fileName);
    
    
    return 0;
}


void parseFile(char * fileName){
    
    FILE * fp;
    char temp;
    int xCount;
    int yCount;
    Square * hold;
    Square * grid[100][100];
    
    fp = fopen(fileName, "r");
    yCount = 0;
    temp = fgetc(fp);
    
    while (temp != EOF){ // while we are not at the end of the file
        xCount = 0;
        while(temp != "\n"){ //while we are not at the end of the line
            
            hold = createSquare(temp, xCount, yCount);
            grid[xCount][yCount] = hold;
            
            if (temp == 'S'){
                start = hold;
                current = hold;
            } else if (temp == 'F')
                finish = hold;
            
            temp = fgetc(fp);
            xCount++; // increment in the x direction
        }
        yCount++;
    }
    
}


Square * createSquare(char v, int x, int y){
    
    Square * newSquare;
    newSquare = malloc(sizeof(Square));
    
    newSquare->val = v;
    
    if (v == '|' || v == '+' || v == '-')
        newSquare->wall = 1;
    else
        newSquare->wall = 0;
    
    newSquare->x = x;
    newSquare->y = y;
    
    if (v == 'S')
        newSquare->wasHere = 1;
    else
        newSquare->wasHere = 0;
    
    return newSquare;
}

