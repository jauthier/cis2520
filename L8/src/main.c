


int main(int argc, char *argv[]){
    
    char * fileName;
    if (argc > 1){
        fileName = argv[1];
    } else {
        printf("Please enter the name of a file.\n");
        exit(0);
    }
    
    List * list = createList();
    list = parseFile(fileName, list);
    
    Element * hold = list->head;
    while (hold != NULL){
        
        
        
        hold = hold->next;
    }
    
    
    return 0;
}