/*
Ilya Besancon
Software Systems Spring 2019

This program is my version of the tee function:
Reads standard input and writes it to both standard output
and one or more files, effectively duplicating its input
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "file_b.txt"

void write_to_file(char* d, char* NAME){
    char c[1000];

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

}


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
    /*
    this is where we process the flags
    printf("argument count: %d\n\n", argc);
    puts("arguments:");
    int i;
    for (i=0; i<argc; i++) {
        printf("\t%s , i = %i\n", argv[i], i);
    }
    */

    //checking for flags
    int flagstatus = 0; //0 is no flag, 1 is append flag
    const char* append_flag = "-a";

    int oper = strcmp(argv[1], append_flag); //checking for equality
    if(oper == 0){
      flagstatus = 1;
    }
    printf("flagstatus is: %i\n", flagstatus);

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
        fputs(line, output);
    }

    free(line);
    fclose(output);
    return 0;
}
