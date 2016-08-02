***************************************************
I have exclusive control over this submission via my password.
By including this file with my submitted files, I certify that:

1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own.

I have appropriately acknowledged any and all material (data, images, ideas or
words) that I have used, whether directly quoted or paraphrased. Furthermore,
I certify that this assignment was prepared by me specifically for this course.\
*****************************************************

CIS 2520 Assignment 2
~~~~~~~~~~~~~~~

Author: Jessica Authier, 0849720
2016/07/08

~~~~~~~~~~~~~~~

Overview:

This program is a reverse look up phone book. I can take in a take a txt file as a command line argument, which will be loaded into a 
linked list. The program uses a hash table to manipulate and search for its entries. The hash function is used was the division method, and 
I used the chaining method to handle collisions. 

This program contains 6 source files(linkedlist.c, hashtable.c, testHT.c, initalize.c, mergeSort.c and main.c) and 4 header files
(linkedlist.h, hashtable.h, initalize.h, mergeSort.h). The linkedlist.c and linkedlist.h files contain the code for the list ADT and are from lab 2. 
The hashtable.c and hashtable.h files contain the code for my hash table ADT, and testHT.c is the file I used to test the ADT. The files initalize.c
and initalize.h, contain functions that specific to the data type used to store the information about the people in the phone book. The files 
mergeSort.c and mergeSort.h contain the functions that are used to recursively sort the linked list containing the entries of the phone book. Finally
main.c contains the main function of the program. 

~~~~~~~~~~~~~~~

Testing:

I have thoroughly tested the linked list ADT in other labs and assignments, thus I did not test it again.

I tested the hash table ADT using the file testHT.c. The file outlines the expected outputs  and the actual outputs of each of the functions in the hash
table ADT. The test file tests all the differnt routes the funtions could possibly take and outlines to the user what is being tested, what the outcome
should be if the function works properly and what the actual outcome is. 

I tested the reading and interpretation of the input file next. I did this by writing a test input file (called file.txt in the docs folder), and 
running it through the function that reads the file and puts it into the linked list. I made sure the function was working properly by printing the 
outputted list and comparing it to the input file. Once the file interpretation was working properly I tested the mergeSort.c file. I tested this by 
printing out the contents of the two lists each time the function mergeSort() was called, and kept track of what it should be using pieces of paper
with the values of the Elements written on them. After the sorting functions were functioning properly I wrote the menu and tested all the functions 
available. I tested then by giving them different inputs and took note whether their outputs were correct, usually by printing the newly changed list. 

~~~~~~~~~~~~~~~

Compiling and Running:

For the phone book type:

To compile type 'make'

To run type './bin/run <inputfilename.txt>'

NOTE: providing an input file is optional


For testing the hash table ADT:

To compile type 'make testHT'

To run type './bin/

~~~~~~~~~~~~~~~

Limitations and Asumptions:

It is assumed that the files inputed will be in th e proper format.

The hash table can only handle keys of type long/int.


