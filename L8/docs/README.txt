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

CIS 2520 Lab 8
~~~~~~~~~~~~~~~

Author: Jessica Authier, 0849720
2016/08/02

~~~~~~~~~~~~~~~

Overview:

This program takes an input file, which contains the information for creating restaurant variables, and puts these variables into two 
binary trees (using the binary tree ADT created by Dr. Judi). One of the trees sorts by name, and the other sorts by rating. The 
contents of the trees are displayed in list form and in tree form. 

This program contains 7 source files(linkedlist.c, restaurant.c, restaurantFunctions.c, testBinTree.c, testFileIn.c, testRestADT.c and
main.c) and 4 header files (linkedlist.h, restaurant.h, restaurantFunctions.h and treeInterface.h). The linkedlist.c and linkedlist.h
files contain the code for the list ADT and are from lab 2. The main.c file is used to run the full program. The restaurant.c and restaurant.h 
files contain the code for the restaurant ADT. The restaurantFunctions.c and restaurantFunctions.h files contain the code for the functions
that are specific to this program (loading/reading the file, putting the restaurants into the binary tree...). The testBinTree.c file is used
for testing some of the functions in the binary tree library. The testFileIn.c file is used to test the function that reads and parses the 
input file. The testRestADT.c file is used to test the Restaurant library.

~~~~~~~~~~~~~~~

Testing:

I have thoroughly tested the linked list ADT in other labs and assignments, thus I did not test it again.

I tested the restaurant ADT using the file testRestADT.c. The file outlines the expected outputs in the comments. The test file tests all the 
differnt routes the funtions could possibly take and outlines, in the comments, what is being tested nad what the outcome should be if the function
works properly. 

I tested the reading and interpretation of the input file next. I did this using the file testFileIn.c and the input file restaurant.txt. I ran the
test program which puts the read in information into a linked list and prints it to the consol. I then compared the printed out data to the input
file, making sure the information was read and parsed correctly.


I tested the treeInterface and some of the restaurantFunctions.c functions using testBinTree.c, which manually enters restaurants, adds them to a tree
and prints them out in order and then in tree form.

~~~~~~~~~~~~~~~

Compiling and Running:

For the main program:

To compile type 'make'

To run type './bin/run <inputfilename.txt>'


For testing the tree functions:

To compile type 'make binTreeTest'

To run type './bin/runTestTree'


For testing the fileInput function:

To compile type 'make fileTest'

To run type './bin/runFileTest <inputfilename.txt>'


For testing the restaurant ADT:

To compile type 'make restaurantTest'

To run type './bin/runTestRest'

~~~~~~~~~~~~~~~

Limitations and Asumptions:

It is assumed that the files inputed will be in the proper format.

I had some trouble with the removeFromTree funtion, it seems like the function frees the memory of the entry
because I get errors with pointer validity when I use other trees containing the entry I have just removed from 
a different list.
Also because of this I was unable to destroy both trees.



