/*
Ilya Besancon
Exercise 02 for Software Systems Spring 2019

This program takes integer input from user until it reads an EOF character
Then converts input strings to integers and stores them in an array.
After reads EOF, should return the sum of the integers.

*/

#include <stdio.h>
#include <stdlib.h>

void main() {
  char input_array[6];
  int sum = 0;

  while(0 < 1) {
    puts("Enter an integer: ");
    scanf("%3s", input_array); //reads in 3 digits at a time
    if (input_array[0] == 'X'){
      break;
    }
    int num = atoi(input_array);
    sum += num;
  }
  printf("Total is: %d\n", sum);
}
