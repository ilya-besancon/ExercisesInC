/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int main ()
{
    int var2 = 5;
    void *p = malloc(16);
    void *q = malloc(16);
    char *s = "Hello, World";

    int j = 3; // initializing local variable

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);

    printf ("q points to %p\n", q);
    printf ("difference is: %p\n", q-p);
    printf ("Address of j is %p\n", &j); //printing address of local variable

    return 0;
}
