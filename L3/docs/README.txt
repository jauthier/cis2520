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

CIS 2520 Lab 3
~~~~~~~~~~~~~~~

Author: Jessica Authier, 0849720
2016/06/03

~~~~~~~~~~~~~~~

Overview:

This program contains three source files(testfile.c, stack.c and linkedlist.c) and two header files(stack.h and linkedlist.h).
The linkedlist.c and linkedlist.h files contain the code for the list ADT and are from lab 2. The stack.c and stack.h files contain the
code for the stack ADT, which is an extension to the list ADT. The stack ADT consists of functions that create and destroy stack 
variables, add and remove elements from the stack, peek at the top Elementof the stack and determine if the stack is empty or not.

testfile.c is used to test all these functions.

~~~~~~~~~~~~~~~

Testing:

Many of the functions in the stack ADT use functions from the list ADT from lab 2. I did not retest 
the functions from the list ADT.

Also I tested using only integers, but from my testing of the list ADT it is known that other data types
work as well.

testfile.c was used to test each of the functions in the stack ADT.

createStack() was tested buy creating a Stack variable and initializing it to the return vaule of createStack,
if the function isEmpty returns true(1) then the stack was inilialized and createStack worked.

push() was tested by creating a Element variables and adding them to the Stack with push and checking if isEmpty
returned true of false and checking if the Element returned from peek was correct Element.

pop() was tested by removing one Element from the Stack and checking the value of the next Element to make sure it was correct.

destroyStack() was tested by passing it the Stack variable created at the beginnig and checking if it produced any errors.

~~~~~~~~~~~~~~~

Compiling and Running:

To compile type 'make'

To run type './bin/l3run'

~~~~~~~~~~~~~~~



