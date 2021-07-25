// Example on reading a file
#include <stdio.h>

int main() {
  FILE *file;  // a pointer to a file
  char name[10], degree[5];
  int mark;
  file = fopen("fileIO", "r"); // open the file to read
  // read through each line of the file until the end of the file
  while (fscanf(file, "%s %s %d", name, degree, &mark)!= EOF)
    printf("%s %s %d\n", name, degree, mark);
  fclose(file);
}
