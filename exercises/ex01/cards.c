/*
Ilya Besancon, Spring 2019

* Program to evaluate face values.
* Released under the Vegas Public License.
* (c)2014 The College Blackjack Team.
*/

#include <stdio.h>
#include <stdlib.h>

int card_val(char * card_name){
  switch(card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    case 'X':
      continue;
    default:
      val = atoi(card_name);
      if ((val <1)||(val > 10)) {
        puts("I don't understand that value!");
        continue;
      }
  }
  return val;
}

void update_count(int val, int *count){
  if ((val >2) && (val <7)) {
    count++;
  } else if (val == 10) {
    count--;
  }
}


int main()
{
  char card_name[3];
  int count = 0;
  int value = 0;
  do {
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    value = card_val(card_name);
    update_count(value, &count);
    printf("current count: %i\n", count);
  } while (card_name[0] != 'X');
return 0;
}
