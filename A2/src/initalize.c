/*
    Author: Jessica Authier
    2016/07/08
*/

#include "initalize.h"

void menuLoop(List * list, Entry ** ht){
    
    int choice;
    
    printf("Welcome to the phonebook!\n");
    
    while(choice != 6){
        
        printMenu();
        scanf("%d", &choice);
        
        long phoneNum;
        
        switch(choice){
            case 1 : ;//load a file
                char * fileName;
                fileName = getInputStr("Enter the name of the file you wish to load: "); // user input
                list = loadFile(fileName, list, ht); // loading new file
                break;
            case 2 : ; // add one entry
                char *ln = getInputStr("Enter the persons last name: ");
                char *fn = getInputStr("Enter the persons first name: ");
                long pn = getInputLong("Enter the persons phone number: ");
                if (exists(ht, pn) == 0){ // key doesn't already exist
                    Person * newPerson = createPerson(ln, fn, pn); // create the person
                    Element * newElement = createElement(newPerson); // create the element it will be stored in in the list
                    insert(ht, ((Person*)newElement->elementPtr)->phoneNum, (Person*)newElement->elementPtr); // add the person to the hash table
                    list = addBack(list, newElement); // add the element to the list
                } else {
                    printf("The phone number you gave is already in the phone book,\n");
                    printf("if you would like to update this number press 4.\n");
                }
                break;
            case 3 : ; // update an entry
                phoneNum = getInputLong("Enter the phone number of the person you wish to update: ");
                char * lastName = getInputStr("Enter the new last name: ");
                char * firstName = getInputStr("Enter the new first name: ");
                if (exists(ht, phoneNum) == 1){ // want it to exist so it can be changed
                    Person * hold = (Person *)lookup(ht, phoneNum); // get the current info
                    Person * replace = createPerson(lastName, firstName, phoneNum); // make a person with the updated info
                    update(ht, phoneNum, replace); // update the hash table
                    Element * toUpdate = searchByValue(list, hold); // get the element that held the old data
                    toUpdate->elementPtr = replace; // change the data in the list
                } else {
                    printf("The phone number you gave is not in the phone book,\n");
                    printf("if you would like to add this number press 2.\n");
                }
                break;
            case 4 : // print all entries
                list = mergeSort(list); // sort the list
                printList(list);
                break;
            case 5 : ; // look up an entry
                phoneNum = getInputLong("Enter the phone number of the person you wish to look up: ");
                Person * found = (Person *)lookup(ht, phoneNum);
                printf("\n%s, %s, %ld was found.\n", found->lastName, found->firstName, found->phoneNum);
                break;
            case 6 : // exit
                printf("Goodbye\n");
                break;
            default : // any other input
                printf("Please enter a number from 1 to 6.\n");
                break;
        }
    }
}

void printMenu(){
    printf("What would you like to do?\n");
    printf("1. Load a file.\n");
    printf("2. Add an enrty.\n");
    printf("3. Update an entry.\n");
    printf("4. Print all entries.\n");
    printf("5. Look up by phone number.\n");
    printf("6. Exit.\n");
    printf("Enter the number of the action you want to complete: ");
}

Element * searchByValue(List *list, void * value){
    
    Element *temp = list->head;
    if (temp == NULL)
        printf("There are no entries to update.\n");
    
    while (temp != NULL){
        if (temp->elementPtr == value)
            return temp;
        temp = temp->next;
    }
    
    return temp;
}

long getInputLong(char * message){
    long num;
    printf("%s",message);
    scanf("%ld", &num);
    return num;
}

char * getInputStr(char * message){
    char *buffer = malloc(sizeof(char) * 100);
    printf("%s",message);
    scanf("%s", buffer);
    return buffer;
}

Person * createPerson(char * ln, char * fn, long pn){
        
    Person * newPerson = malloc(sizeof(Person));
    
    newPerson->lastName = malloc(sizeof(char)*strlen(ln));
    strcpy(newPerson->lastName, ln);
    
    newPerson->firstName = malloc(sizeof(char)*strlen(fn));;
    strcpy(newPerson->firstName, fn);
    
    newPerson->phoneNum = pn;
    
    return newPerson;
}

List * loadFile(char * fileName, List *list, Entry ** ht){
    
    FILE *fp;
    char *firstName, *lastName, *phoneNum, *temp;
    char buffer[200];
    
    
    fp = fopen(fileName, "r");
    if (fp == NULL){
        printf("File not found!\n");
    }
    
    while (fgets(buffer, 200, fp) != NULL){
        lastName = strtok(buffer, ",");
        firstName = strtok(NULL, ",");
        phoneNum = strtok(NULL, ", \n");
        long hold = strtol((char*)phoneNum, &temp, 10);
        
        Person * newPerson = createPerson(lastName, firstName, hold);
        Element * newElement = createElement(newPerson);
        insert(ht, ((Person*)newElement->elementPtr)->phoneNum, (Person*)newElement->elementPtr);
        list = addBack(list, newElement);
    }
    fclose(fp);
    return list;
}



void printList(List * list){
    
    Element * temp = list->head;
    while (temp != NULL){
    char *ln = ((Person*)(temp->elementPtr))->lastName;
    char *fn = ((Person*)(temp->elementPtr))->firstName;
    long num = ((Person*)(temp->elementPtr))->phoneNum;
        printf("%s, %s, %ld\n", ln, fn, num);
        temp = temp->next;
    }
}
