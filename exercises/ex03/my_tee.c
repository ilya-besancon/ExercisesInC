/*
Ilya Besancon
Software Systems Spring 2019
version 1.0

NOTE: currently takes in 0-1 flags and only 1 file

This program is an implementation of tee:
Reads standard input and writes it to both standard output
and one or more files, effectively duplicating its input

Ex03 Questions post exercise:
3. Reflect upon what worked and what I would do differently

  Divide and conquer.
  Read enough google to understand the function itself and
  examples of how to read/write files, take in stdin, etc.

4. Compare solution to example implementation

  The professional code is definitely different from my solution.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * The integer, argc is the argument count. It is the number of arguments passed
 * into the program from the command line, including the name of the program.
 *
 * The array of character pointers is the listing of all the arguments. argv[0]
 * is the name of the program, or an empty string if the name is not available.
 * After that, every element number less than argc is a command line argument.
 * You can use each argv element just like a string, or use argv as a two
 * dimensional array. argv[argc] is a null pointer.
 */
int main (int argc, char *argv[] )
{
    //checking for flags
    int flagstatus = 0; //0 is no flag, 1 is append flag
    const char* append_flag = "-a";

    int oper = strcmp(argv[1], append_flag); //checking for equality
    if(oper == 0){
      flagstatus = 1;
    }
    //printf("flagstatus is: %i\n", flagstatus);

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    FILE *output;
    if(flagstatus == 1){
      output = fopen(argv[2], "a"); //open in append mode
    }
    else {
      output = fopen(argv[1], "wb"); //open in write mode
    }

    while ((read = getline(&line, &len, stdin)) != -1) {
        printf("%s", line);
        fputs(line, output);
    }

    free(line);
    fclose(output);
    return 0;
}
