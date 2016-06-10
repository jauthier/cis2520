
#include "maze.h"

Square * current;
Square * start;
Square * finish;
Square * maze[100][100];
Stack * solution;
int sizeX;
int sizeY;
char dir;

void stackThing();

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
    printf("in checkUp\n");
    
    if (maze[x][y-1]->wall == 0){
        return 1;
    }
    return 0;
}

int checkDown(){
   
    int x, y;
    x = current->x;
    y = current->y;
    printf("in checkDown\n");
    
    if (maze[x][y+1]->wall == 0){
        return 1;
    }
    return 0;
}

int checkRight(){
   
    int x, y;
    x = current->x;
    y = current->y;
    printf("in checkRight\n");

    if (maze[x+1][y]->wall == 0){
        return 1;
    }
    return 0;
}

int checkLeft(){
   
    int x, y;
    x = current->x;
    y = current->y;
    printf("in checkLeft\n");
    
    if (maze[x-1][y]->wall == 0){
        printf("no wall\n");
        return 1;
    }
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

void stackThing(){

    Element * hold;
    hold = solution->top->head;
    
    while (hold != NULL){
        Square * temp = (Square *)hold->elementPtr;
        temp->val = '.';
        hold = hold->next;
        
    }
}

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
                printf("last: (%d, %d)\n",lastX,lastY);
                if (otherOptions(lastX, lastY) == 1){ // there are other options
                    changeDir();
                } else { // no other options will need to go back to where we have been
                     pop(solution); // pop from stack
        lastX = current->x;
        lastY = current->y;
        printf("(%d, %d)\n", lastX, lastY);
                    current = maze[nextX][nextY]; // move
                }
            } else {
        lastX = current->x;
        lastY = current->y;
        printf("(%d, %d)\n", lastX, lastY);
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

int otherOptions(int lastX, int lastY){
    //check if there are other open squares next to the current
    int x, y, up, down, left, right;
    x = current->x;
    y = current->y;

    printf("%d, %d\n",lastX, lastY);

    up = maze[x][y-1]->wasHere;
    if ((maze[x][y-1]->wall == 1)||(x == lastX && y-1 == lastY))
        up = 1;
    down = maze[x][y+1]->wasHere;
    if ((maze[x][y+1]->wall == 1)||(x == lastX && y+1 == lastY))
        down = 1;
    right = maze[x+1][y]->wasHere;
    if ((maze[x+1][y]->wall == 1)||(x+1 == lastX && y == lastY))
        right = 1;
    left = maze[x-1][y]->wasHere;
    if ((maze[x-1][y]->wall == 1)||(x-1 == lastX && y == lastY))
        left = 1;

    if ((up == 0)||(down == 0)||(left == 0)||(right == 0))
        return 1;
    else 
        return 0;
}
