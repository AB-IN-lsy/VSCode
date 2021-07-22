// An example on pass-by-value and pass-by-reference.
//
// The program swaps the value of two variables through 
// two functions that use pass-by-value and pass-by-reference
// respectively in parameters passing.
#include <stdio.h>

void swap1(int i, int j);  // Function that uses pass-by-value.
void swap2(int* i, int* j);  // Function that uses pass-by-reference.
int main() {
  int a = 12, b = 13;
  printf("Initial values:\n");
  printf("a = %d  b = %d\n\n", a, b);
  swap1(a, b);
  printf("After swap1:\n");
  printf("a = %d  b = %d\n\n", a, b);
  swap2(&a, &b);
  printf("After swap2:\n");
  printf("a = %d  b = %d\n", a, b);
}

void swap1(int i, int j) {
  int temp;
  temp = i;
  i = j;
  j = temp;
}

void swap2(int* i, int* j) {
  int temp;
  temp = *i;
  *i = *j;
  *j = temp;
}
