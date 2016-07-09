/*
    Author: Jessica Authier
    2016/07/08
*/

#include "initalize.h"

void menu(List * list, Entry ** ht){
    
    int choice;
    
    printf("Welcome to the phonebook!\n");
    
    while(choice != 7){
        
        printf("What would you like to do?\n");
        printf("1. Load a file.\n");
        printf("2. Add an enrty.\n");
        printf("3. Remove an entry.\n");
        printf("4. Update an entry.\n");
        printf("5. Print all entries.\n");
        printf("6. Look up by phone number.\n");
        printf("7. Exit.\n");
        printf("Enter the number of the action you want to complete: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1 : ;
                char * fileName;
                fileName = getInputStr("Enter the name of the file you wish to load: ");
                list = loadFile(fileName, list, ht);
                list = mergeSort(list);
                break;
            case 2 : ;
                char *ln, *fn, *pn;
                ln = getInputStr("Enter the persons last name: ");
                fn = getInputStr("Enter the persons first name: ");
                pn = getInputStr("Enter the persons phone number: ");
                Person * newPerson = createPerson(ln, fn, pn);
                Element * newElement = createElement(newPerson);
                insert(ht, ((Person*)newElement->elementPtr)->phoneNum, (Person*)newElement->elementPtr);
                list = addBack(list, newElement);
                list = mergeSort(list)
                break;
            case 3 :
                long phoneNum = getInputLong("Enter the phone number of the person you wish to remove: ");
                Person * toRm = (Person *)removeEntry(ht, phoneNum);
                printf("%s, %s, %ld was removed.\n", toRm(->lastName, toRm->firstName, toRm->phoneNum);
                break;
            case 4 :
                
                break;
            case 5 :
                
                break;
            case 6 :
                break;
            case 7 :
                break;
            default :
            
        }
        
    }
}

long getInputLong(char * message){
    long num;
    printf("%s",message);
    scanf("%ld", &num);
    return num;
}

char * getInputStr(char * message){
    char buffer[100];
    printf("%s",message);
    fgets(buffer, 100, stdin);
    return buffer;
}

Person * createPerson(char * ln, char * fn, char * pn){
    
    char *temp;
    long hold;
    Person * newPerson = malloc(sizeof(Person));
    
    newPerson->lastName = malloc(sizeof(char)*strlen(lastName));
    strcpy(newPerson->lastName, lastName);
    
    newPerson->firstName = malloc(sizeof(char)*strlen(firstName));;
    strcpy(newPerson->firstName, firstName);
    
    hold = strtol((char*)phoneNum, &temp, 10);
    newPerson->phoneNum = hold;
    
    return newPerson;
}

List * loadFile(char * fileName, List *list, Entry ** ht){
    
    FILE *fp;
    char *firstName, *lastName, *phoneNum;
    char buffer[200];
    
    
    fp = fopen(fileName, "r");
    if (fp == NULL){
        printf("File not found!\n");
        exit(0);
    }
    
    while (fgets(buffer, 200, fp) != NULL){
        lastName = strtok(buffer, ",");
        firstName = strtok(NULL, ",");
        phoneNum = strtok(NULL, ", \n");
        
        Person * newPerson = createPerson(lastName, firstName, phoneNum);
        Element * newElement = createElement(newPerson);
        insert(ht, ((Person*)hold->elementPtr)->phoneNum, (Person*)hold->elementPtr);
        list = addBack(list, newElement);
    }
    fclose(fp);
    return list;
}

List * mergeSort(List * list){
    
    Element * head = list->head;
    List * list1 = createList();
    List * list2 = createList();
    
    if (getLength(list)<2)
        return list;

    list1->head = head;
    list2->head = bisectList(head)->next;
    bisectList(head)->next = NULL;

    list1 = mergeSort(list1);
    list2 = mergeSort(list2);

    return mergeLists(list1->head, list2->head);
}

List * mergeLists(Element * list1, Element * list2){
    List * result  = createList();
    Element * current = NULL;
    
    if (list1 == NULL){
        result->head = list1;
        return result;
    }
    
    if (list2 == NULL){
        result->head = list2;
        return result;
    }
    
    while (list1 != NULL && list2 != NULL){
        
        Element * temp;
        
        if (compareNames(list1, list2) == 1){//then list1 has the lower value
            temp = list1;
            list1 = list1->next;
            temp->next = NULL;
        } else{ // compareNames must have returned 2, thus list2 is lower or they are the same
            temp = list2;
            list2 = list2->next;
            temp->next = NULL;
        }

        if (result->head == NULL){ // if there are no elements in the result yet
            result->head = temp; // set the new element to be the first
            current = result->head; // and set the current pointer to it
        } else { // if there are elements in the result
            current->next = temp; // add the new element after the current
            current = temp; // and switch the current pointer
        }
    }
    while (list1 != NULL){
        Element * temp;
        temp = list1;
        list1 = list1->next;
        temp->next = NULL;
        current->next = temp;
        current = temp;
    }
    
    while(list2 != NULL){
        Element * temp;
        temp = list2;
        list2 = list2->next;
        temp->next = NULL;
        current->next = temp;
        current = temp;
    }
    
    return result;
}

Element * bisectList(Element * head){
    
    List * temp = createList();
    temp->head = head;
    int len = getLength(temp);
    if (len < 2)
        return NULL;
    else {
        if (len%2 == 0){ // even number of elements
            len = len/2 - 1;
        } else {
            len = len/2;
        }

        for (int i=0; i<len; i++){
            head = head->next;
        }
        return head;
    }
}

int compareNames(Element * first, Element * second){
    
    char * name1 = ((Person *)first->elementPtr)->lastName;
    char * name2 = ((Person *)second->elementPtr)->lastName;
    
    if (strcmp(name1, name2)<0)
        return 1;
    else
        return 2;
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
