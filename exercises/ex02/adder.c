/*
Ilya Besancon
Exercise 02 for Software Systems Spring 2019

This program takes integer input from user until it reads an EOF character
Then converts input strings to integers and stores them in an array.
After reads EOF, should return the sum of the integers.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //included to allow for atoi and strlen functions

#define BUFFER_SIZE 15

/*
Takes in the integer input and int pointer to status.
Updates status based on valid/invalid input
*/
void check_input(int number, int* status){
  if (number > 0){
    *status = 1;
  }
  else {
    *status = 0;
  }
}

int main() {
  char input_array[10];
  int sum = 0;
  int number;
  int status;

  while(scanf("%s", input_array) != EOF){ //checks for EOF to break loop
    int length = strlen(input_array);
    printf("Length is %i\n", length);

    if (length < BUFFER_SIZE){
      number = atoi(input_array); //returns 0 if string
      check_input(number, &status); //updates status
      if(status == 1){ //everything is a ok
        printf("Adding %i\n", number);
        sum += number; //updates sum
      }
      else { //input must be invalid
        printf("Invalid input!\n");
        break;
      }
    }
    else { // length must exceed buffer, too long
      printf("Input is too long!\n");
      break;
    }
  }
  printf("Total is: %d\n", sum); //prints total
  return 0;
}
