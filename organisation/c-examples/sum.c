// An example that shows how to handle command line arguments in C
//
// The program accepts two integers from command line, 
// and prints out the sum of the two integers.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) 
    printf("usage: %s operand1 operand2\n", argv[0]);
  else {
    long operand1, operand2;
    char *ptr;
    // Convert string to integers.
    // It is assumed that the arguments are valid integers.
    // So, no validation is carried out.
    operand1 = strtol(argv[1], &ptr, 10);
    operand2 = strtol(argv[2], &ptr, 10);
    printf("%d + %d = %d\n", operand1, operand2, operand1+operand2);
  }
}
