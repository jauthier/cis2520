/*
    Author: Jessica Authier
    2016/06/10
*/

#include "linkedlist.h"
#include "stack.h"
#include "maze.h"


int main(int argc, char * argv[]){
    
    char * fileName;
    
    if (argc != 2){
        printf("Incorrect input\n");
        exit(0);
    }
    
    fileName = argv[1];
    
    parseFile(fileName);
    
    printf("Finished parsing\n");
    printMaze();
    
    solution = createStack();
    printf("Stack created\n");
    navigate();
    stackThing();
    printMaze();

    return 0;
}

void navigate(){
    
    int check, nextX, nextY;
    initDir(); //start by getting the initial direction
    push(solution, current); // add the starting square to the stack
    
    while (current->val != 'F'){  // the maze sloving loop
        printf("in loop: (%d, %d)\n",current->x, current->y);
        check = checkNext();
        
        printf("switch return: %d\n",check);
        char c = getchar();
        
        if (check == 1){ // if you can move, the next space is not a wall
            printf("wasHere: %d\n",maze[nextX][nextY]->wasHere);
            if (maze[nextX][nextY]->wasHere == 1){ //we have been there already
                
                if (otherOptions() == 1){ // there are other options
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
            printf("changing dir. before: %c\n",dir);
            changeDir();
            printf("after: %c\n",dir);
        }
    }
}

