/*
    Author: Jessica Authier
    2016/06/10
*/

#include "linkedlist.h"
#include "stack.h"
#include "maze.h"

void navigate();

int main(int argc, char * argv[]){
    
    char * fileName;
    
    if (argc != 2){
        printf("Incorrect input\n");
        exit(0);
    }
    
    fileName = argv[1];
    
    parseFile(fileName);
    
    printMaze();
    
    solution = createStack();
    
    navigate();
    setPath();
    printMaze();

    return 0;
}

void navigate(){
    
    int check, nextX, nextY;
    initDir(); //start by getting the initial direction
    push(solution, current); // add the starting square to the stack
    
    while (current->val != 'F'){  // the maze sloving loop
        check = checkNext();
        
        if (check == 1){ // if you can move, the next space is not a wall
            if (maze[nextX][nextY]->wasHere == 1){ //we have been there already
                if (otherOptions(nextX, nextY) == 1){ // there are other options
                    changeDir();
                } else { // no other options will need to go back to where we have been
                    pop(solution); // pop from stack
                    current->deadEnd = 1;
                    current = maze[nextX][nextY]; // move
                }
            } else {
                current = maze[nextX][nextY]; // move
                current-> wasHere = 1;
                push(solution, current); // add to stack
            }
        } else {
            changeDir();
        }
    }
}