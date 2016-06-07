
#include "maze.h"

Square * current;
Square * start;
Square * finish;
Square * maze[100][100];
int sizeX;
int sizeY;

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
    return 0;
}

void parseFile(char * fileName){
    
    FILE * fp;
    char temp;
    int xCount;
    int yCount;
    Square * hold;
    
    fp = fopen(fileName, "r");
    if (fp == NULL)
        printf("no such file\n");
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
    printf("%d, %d\n",sizeX, sizeY);
    for (i=0;i<sizeY;i++){
        j=0;
        for(j=0;j<sizeX;j++){
//    printf("%d, %d", j, i);

            printf("%c",maze[j][i]->val);
            fflush(stdout);
        }

//    printf("here\n");

        printf("\n");
    }
    
}
