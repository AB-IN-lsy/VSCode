// Print the command line argument character by character
#include <stdio.h>
int main(int argc, char *argv[]) {
  int i = 0;
  while (*(argv[1]+i)!='\0') {
    printf("%c",*(argv[1]+i));
    i++;
  }
  printf("\n");
}
