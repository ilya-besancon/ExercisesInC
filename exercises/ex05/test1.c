#include <stdio.h>
#include <stdlib.h>

#include <time.h> //for time
#include "rand.h"


int main (int argc, char *argv[])
{
    int i;
    double x;

    srandom (time (NULL));

    for (i=0; i<10000; i++) {
        x = random_float(); //something was problematic here in compiling..
        printf ("%lf\n", x);
    }
    return 0;
}
