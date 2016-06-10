
#include "maze.h"

Square * current;
Square * start;
Square * finish;
Square * maze[100][100];
Stack * solution;
int sizeX;
int sizeY;
char dir;

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
    
    return 0;
}

void parseFile(char * fileName){
    
    FILE * fp;
    char temp;
    int xCount;
    int yCount;
    Square * hold;
    
    fp = fopen(fileName, "r");
    if (fp == NULL){ // check to make sure file opened
        printf("no such file\n");
        exit(0);
    }
    
    yCount = 0;
    temp = fgetc(fp);
    
    while (temp != EOF){ // while we are not at the end of the file
        xCount = 0;
        while(temp != '\n'){ //while we are not at the end of the line
            //printf("%d ,%d\n",xCount, yCount);
            hold = createSquare(temp, xCount, yCount);
            maze[xCount][yCount] = hold;
            
            if (temp == 'S'){
                start = hold;
                current = hold;
            } else if (temp == 'F')
                finish = hold;
            
            temp = fgetc(fp);
            xCount++; // increment in the x direction
        }
	temp = fgetc(fp);
        yCount++;
    }
    
    sizeX = xCount;
    sizeY = yCount;
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

void printMaze(){
    int i,j;
    
    for (i=0;i<sizeY;i++){
        j=0;
        for(j=0;j<sizeX;j++){
            printf("%c",maze[j][i]->val);
            fflush(stdout);
        }
        printf("\n");
    }
}

void initDir(){
    //get start position
    //start position will be on the outer wall so the starting direction will 
    //be pointing into the maze from that wall
    
    if (start->x == 0) // start is on the left wall
        dir = 'e';
    else if (start->x == sizeX - 1) // start is on the right wall
        dir = 'w';
    else if (start->y == 0) // start is on the upper wall 
        dir = 's';
    else if (start->y == sizeY - 1) // start is on the lower wall
        dir = 'n';
    
}

int checkUp(){
   
    int x, y;
    x = current->x;
    y = current->y;
    
    if (maze[x][y-1]->wall == 0){
        return 1;
    }
    return 0;
}

int checkDown(){
   
    int x, y;
    x = current->x;
    y = current->y;
    
    if (maze[x][y+1]->wall == 0){
        return 1;
    }
    return 0;
}

int checkRight(){
   
    int x, y;
    x = current->x;
    y = current->y;
    
    if (maze[x+1][y]->wall == 0){
        return 1;
    }
    return 0;
}

int checkLeft(){
   
    int x, y;
    x = current->x;
    y = current->y;
    
    if (maze[x-1][y]->wall == 0){
        return 1;
    }
    return 0;
}

void changeDir(){
    
    switch (dir){
        case 'n':
           dir = 'e'; 
        case 's':
            dir  = 'w';
        case 'e':
            dir = 's';
        case 'w':
            dir = 'n';
    }
 }

void navigate(){
    
    // this is where the maze will be solved
    //start by getting the initial direction
    int check, nextX, nextY;
    initDir();
    
    //add the staeting square to the spot
    push(solution, current);
    
    while (current->val != 'F'){
        
        //can i go forward?
        switch(dir){
            case 'n':
                check = checkUp();
                nextX = current->x - 1;
                nextY = current->y;
            case 's':
                check = checkDown();
                nextX = current->x + 1;
                nextY = current->y;
            case 'e':
                check = checkRight();
                nextX = current->x;
                nextY = current->y + 1;
            case 'w':
                check = checkLeft(); 
                nextX = current->x;
                nextY = current->y - 1;
        }
        
        if (check == 1){ // if you can move, the next space is not a wall 
            if (maze[nextX][nextY]->wasHere == 1){ //we have been there already
                if (){ // there are other options
                    changeDir();
                } else { // no other options will need to go back to where we have been
                     pop(solution); // pop from stack
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

