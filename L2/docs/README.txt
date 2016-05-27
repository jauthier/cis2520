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

CIS 2520 Lab 2 
~~~~~~~~~~~~~~~

Author: Jessica Authier, 0849720
2016/05/27

~~~~~~~~~~~~~~~

Overview:

This program contains two source files(testFile.c and linkedlist.c) and one header file(linkedlist.h).
The linkedlist.c and linkedlist.h files contain the code for the list ADT. The list ADT consists of functions
that create and destroy lists and elements, add and remove elements from both the front and back of the list,
return the length of the list and return the first  element of the list.

testFile.c is used to test all these functions.

~~~~~~~~~~~~~~~

Testing:

testFile.c was used to test each of the functions in the ADT.

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

~~~~~~~~~~~~~~~


