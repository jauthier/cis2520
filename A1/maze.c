
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
    
    
    return 0;
}

void parseFile(char * fileName){
    
    FILE * fp;
    char temp;
    int xCount;
    int yCount;
    Square * hold;
    
    fp = fopen(fileName, "r");
    yCount = 0;
    temp = fgetc(fp);
    
    while (temp != EOF){ // while we are not at the end of the file
        xCount = 0;
        while(temp != '\n'){ //while we are not at the end of the line
            
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
        yCount++;
    }
    
    sizeX = xCount + 1;
    sizeY = yCount + 1;
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
            
        }
        printf("\n");
    }
    
}
