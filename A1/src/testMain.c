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
    testNavigate();
    stackThing();
    printMaze();

    return 0;
}


