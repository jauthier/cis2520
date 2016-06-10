/*
    Author: Jessica Authier
    2016/06/10
*/

#include "maze.h"

Square * current;
Square * maze[100][100];
Stack * solution;
int sizeX;
int sizeY;
char dir;

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
            hold = createSquare(temp, xCount, yCount);
            maze[xCount][yCount] = hold;   
            if (temp == 'S'){
                current = hold;
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
    newSquare->deadEnd = 0;
    
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
    
    if (maze[x][y-1]->wall == 0)
        return 1;
    return 0;
}

int checkDown(){
   
    int x, y;
    x = current->x;
    y = current->y;
    
    if (maze[x][y+1]->wall == 0)
        return 1;
    return 0;
}

int checkRight(){
   
    int x, y;
    x = current->x;
    y = current->y;

    if (maze[x+1][y]->wall == 0)
        return 1;
    return 0;
}

int checkLeft(){
   
    int x, y;
    x = current->x;
    y = current->y;
    
    if (maze[x-1][y]->wall == 0)
        return 1;
    return 0;
}

void changeDir(){
    
    switch (dir){
        case 'n':
           dir = 'e';
           break;
        case 's':
            dir  = 'w';
            break;
        case 'e':
            dir = 's';
            break;
        case 'w':
            dir = 'n';
            break;
    }
}

int checkNext(){
    int check;
    switch(dir){
        case 'n':
            check = checkUp();
            nextX = current->x;
            nextY = current->y - 1;
            break;
        case 's':
            check = checkDown();
            nextX = current->x;
            nextY = current->y + 1;
            break;
        case 'e':
            check = checkRight();
            nextX = current->x + 1;
            nextY = current->y;
            break;
        case 'w':
            check = checkLeft(); 
            nextX = current->x - 1;
            nextY = current->y;
            break;
    }
    return check;
}

void setPath(){

    Element * hold;
    hold = solution->top->head;
    
    while (hold != NULL){
        Square * temp = (Square *)hold->elementPtr;
        temp->val = '.';
        hold = hold->next;
        
    }
}

<<<<<<< HEAD
void navigate(){
    
    // this is where the maze will be solved
    //start by getting the initial direction
    int check, nextX, nextY, lastX, lastY;
    initDir();
    //add the staeting square to the spot
    push(solution, current);
    printf("first square added\n");
    
    while (current->val != 'F'){
        printf("in loop: (%d, %d)\n",current->x, current->y);

        //can i go forward?
        switch(dir){
            case 'n':
                check = checkUp();
                nextX = current->x;
                nextY = current->y - 1;
                break;
            case 's':
                check = checkDown();
                nextX = current->x;
                nextY = current->y + 1;
                break;
            case 'e':
                check = checkRight();
                nextX = current->x + 1;
                nextY = current->y;
                break;
            case 'w':
                check = checkLeft(); 
                nextX = current->x - 1;
                nextY = current->y;
                break;
        }
        printf("switch return: %d\n",check);
        char c = getchar();
        
        if (check == 1){ // if you can move, the next space is not a wall
            printf("wasHere: %d\n",maze[nextX][nextY]->wasHere);
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
            printf("changing dir. before: %c\n",dir);
            changeDir();
            printf("after: %c\n",dir);
        }
    }
}

=======
>>>>>>> 1e7415ed004ea0766ce208c030c1bb6a1a1c9238
int otherOptions(int nextX, int nextY){

    int x, y, up, down, left, right;
    x = current->x;
    y = current->y;

    up = maze[x][y-1]->wasHere; // have we been there already
    if (maze[x][y-1]->deadEnd == 0) // its not a dead end
        up = 0;
    if (x == nextX && y-1 == nextY) // its the current next square
        up = 1;
    if (maze[x][y-1]->wall == 1) // its a wall
        up = 1;
    
    down = maze[x][y+1]->wasHere;
    if (maze[x][y+1]->deadEnd == 0)
        down = 0;
    if (x == nextX && y+1 == nextY)
        down = 1;
    if (maze[x][y+1]->wall == 1)
        down = 1;
    
    right = maze[x+1][y]->wasHere;
    if (maze[x+1][y]->deadEnd == 0)
        right = 0;
    if (x+1 == nextX && y == nextY)
        right = 1;
    if (maze[x+1][y]->wall == 1)
        right = 1;
    
    left = maze[x-1][y]->wasHere;
    if (maze[x-1][y]->deadEnd == 0)
        left = 0;
    if (x-1 == nextX && y == nextY)
        left = 1;
    if (maze[x-1][y]->wall == 1)
        left = 1;

    if ((up == 0)||(down == 0)||(left == 0)||(right == 0)) // if not a wall and haven't been there or we have been there but it wasnt a dead end
        return 1;
    else 
        return 0;
}
