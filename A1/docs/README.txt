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

CIS 2520 Assignment 1
~~~~~~~~~~~~~~~

Author: Jessica Authier, 0849720
2016/06/10

~~~~~~~~~~~~~~~

Overview:

This program contains 7 source files(stack.c, linkedlist.c, maze.c, main.c, mazeTest.c, stackTest.c and listTest.c) and 3 header files
(stack.h, linkedlist.h and maze.h). The linkedlist.c and linkedlist.h files contain the code for the list ADT and are from lab 2. 
The stack.c and stack.h files contain the code for the stack ADT from lab 3, which is an extension to the list ADT. The maze. and maze.h files
contain all the functions required to parse a maze text file and find the solution to the maze. main.c is the file that runs the maze solver.
mazeTest.c is the files that was used to test the maze solver. stackTest.c was use to test the stack ADT, and is very similar to the test file
from lab 3. listTest.c was used to test the list ADT and is very similar to the test files used in lab 2.

~~~~~~~~~~~~~~~

Testing:

Linkedlist ADT:
listTest.c was used to test all the functions in the linkedlist ADT

createList() was tested buy creating a List variable and initializing it to the return vaule of createList,
if the list variable is equal to NUULL then the function didn't work.

createElement() was tested by creating several Element variables and initializing them to the values returned from 
createElement. I used different types of pointers as the parameter to test the generality.

addFront(),  addBack(), getLength() and getFront() were tested together by adding a Element to the testList with addFront
or addBack and checking if the length returned by getLength was correct and checking if the Element returned from getFront
was correct.

removeBack() was tested by removing all of the Elements from the testListthat were added in the preivious test.
After each Element was removed the Element that was removed, the length and the first Element were printed out.
removeBack was also called with an empty List as the parameter to see how it handles it.

removeFront() was tested by adding two Elements to the testList(since it was empty from the last test) and removing them.
Like before after each Element was removed the Element that was removed, the length and the first Element were printed out.
removeFront was also called with an empty List as the parameter to see how it handles it.

destroyList() and destroyElement() were tested by passing them the List variable and Element variables created at the
beginnig.

Stack ADT:

stackTest.c was used to test the functions in the stack ADT

Also I tested using only integers, but from my testing of the list ADT it is known that other data types
work as well.

testfile.c was used to test each of the functions in the stack ADT.

createStack() was tested buy creating a Stack variable and initializing it to the return vaule of createStack,
if the function isEmpty returns true(1) then the stack was inilialized and createStack worked.

push() was tested by creating a Element variables and adding them to the Stack with push and checking if isEmpty
returned true of false and checking if the Element returned from peek was correct Element.

pop() was tested by removing one Element from the Stack and checking the value of the next Element to make sure it was correct.

destroyStack() was tested by passing it the Stack variable created at the beginnig and checking if it produced any errors.

Maze Solver:

mazetest.c was used to test the maze solver.

First I tested the reading and translation of the input file by reading in the file and printing the inputed maze to the screen 
and comparing it to the input file.

Once I made sure the input file was read correctly I tested the navigation aspects, printing out reports as each actions were executed.

Backtracking was the hardest part and required the most testing.

The main way I tested was by running mazes of different difficulties through the solver and analysing how they were solved.

~~~~~~~~~~~~~~~

Compiling and Running:

For the maze solver:

To compile type 'make'

To run type './bin/runSolver <inputfilename.txt>'


For testing the maze solver:

To compile type 'make mazeTest'

To run type './bin/mazeTestRun <inputfilename.txt>'


For testing the stack ADT:

To compile type 'make stackTest'

To run type './bin/stackRun'


For testing the list ADT:

To compile type 'make listTest'

To run type './bin/listRun'


~~~~~~~~~~~~~~~

Limitations and Asumptions:

It is assumed that the start and finish points are on the edges and not in the corners.

It is not gaurenteed that the solver will come up with the shortest solution to the maze.



