/*
Read text file,
split lines into words,
count frequency of each word,
display frequencies
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n_lines; //creates global for number of lines in file

char** read_file(FILE *fp){

    char **stringarray = malloc(2000000); /* I don't understand why you use pointer to pointer than pointer, char **stringarray[2]; */
    int large = 1000;
    char buffer[large]; /* I suggest 6 than 5, because string has terminate byte in C */
    int i = 0;
    while(fgets(buffer, large, fp) != NULL){
        stringarray[i] = strndup(buffer, large);
        i++;
    }
    n_lines = i;
    printf("Number of lines: %d\n", n_lines);
    return stringarray;
}

void print_array(char ** array){
    printf("Running print_array\n");
    for(int i = 0; i < n_lines; i++){
        printf("%s", array[i]); /* changed stringarray */
    }
}

int main(int argc, char *argv[]){
    // printf("File name is: %s\n", argv[1]);
    FILE *fp = fopen(argv[1], "r"); // opens file in read mode
    char **stuff = read_file(fp);
    //print_array(stuff);
    return 0;
}
