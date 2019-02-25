/*
Ilya Besancon
Software Systems Spring 2019
version 1.1

NOTE: currently takes in the -a flag and any number of files

This program is an implementation of tee:
Reads standard input and writes it to both standard output
and one or more files, effectively duplicating its input

Ex03 Questions post exercise:
3. Reflect upon what worked and what I would do differently

  Divide and conquer worked well in collaborating in the initial stages
  of programming. It was helpful to split up the tasks into different functions.
  I had to read enough google to understand the function itself and
  examples of how to read/write files, take in stdin, etc.

4. Compare solution to example implementation

  The professional code is definitely different from my solution.
  It is more neatly segmented, and has more implemented functionality.
  For example, it implements switch cases. Additionally, it has more noticeable
  indentation in the formatting of the code. I also found it interesting
  how it implements the malloc function. 

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


// Writes/appends line to all the files that have been passed in
void writefile(char* argv[], int argc, int flagstatus, char * line) {
    FILE *output;

    //if append flag is present
    if (flagstatus == 1){
      int b;
      for(b=2; b < argc; b++){
        output = fopen(argv[b], "a"); //open in append mode
        fputs(line, output);;
      }
    }

    //default, write to file
    else {
      int b;
      for(b=1; b < argc; b++){
        output = fopen(argv[b], "wb"); //open in append mode
        fputs(line, output);
      }
    }

    free(line);
    fclose(output);
}


int main (int argc, char *argv[] )
{
    //checking for flags
    int flagstatus = 0; //0 is no flag, 1 is append flag
    const char* append_flag = "-a";
    printf("Number of arguments: %i\n", argc);
    int i;
    for (i=0; i<argc; i++) {
        printf("Inputs: %s\n", argv[i]);
    }
    int oper = strcmp(argv[1], append_flag); //checking for equality
    if(oper == 0){
      flagstatus = 1;
    }
    //printf("flagstatus is: %i\n", flagstatus);

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1) {
        printf("%s", line);
        printf("Line is %s\n", line);
        writefile(argv, argc, flagstatus, line);
    }
    return 0;
}
