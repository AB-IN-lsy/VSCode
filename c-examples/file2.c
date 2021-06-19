// Example on file IO
//
// The program read each line of the file,
// counts the number of characters in each line,
// prints the line and the number of characters in the line
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
  FILE *file;
  char line[20];
  int counter=0;
  file = fopen("fileIO2", "r");
  // each iteration of the do-loop process one line of the file
  do {
    char c = fgetc(file);
    if (c == EOF) break;
    memset(line, 0, 20); // resets the contents of array before a line is read
    // the while-loop reads in one line
    while ((c != '\n')&&(c != EOF)) {
      line[counter++] = c;
      c = fgetc(file);
    }
    printf("%s  %d\n", line, counter);
    counter=0;
  } while (true);
  fclose(file);
}
