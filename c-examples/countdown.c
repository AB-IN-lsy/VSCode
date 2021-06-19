#include <stdio.h>
#define STOP 0

/* Function: main                                   */
/* Description: counts down from user input to STOP */
int main()
{
  /* variable declarations */
  int counter;  /* an integer to hold count values */
  int startPoint; /* starting point for countdown */
  /* prompt user for input */
  printf("Enter a positive number: ");
  scanf("%d", &startPoint);  /* read into startPoint */
  /* count down and print count */
  for (counter=startPoint; counter >= STOP; counter--)
    printf("%d\n", counter);
}
