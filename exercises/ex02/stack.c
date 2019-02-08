/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

Experimentation results:
  -when trying to run code, get seg fault
  -in compiling, issue w/ returning address of local variable to main()
  -the address is pointing to something in the foo stackframe, which doesn't exist more
  -commenting out the print statements doesn't resolve the seg fault either
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 //init global variable, SIZE

int *foo() {
    int i;
    int array[SIZE];

    //printf("%p\n", array); //prints out address of array

    for (i=0; i<SIZE; i++) {
        array[i] = 42; //populate array indexes w/ value of 42
    }
    return array; //trying to return address of variable created w/ in the foo stack frame
}

void bar() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
