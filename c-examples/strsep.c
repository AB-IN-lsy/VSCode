#include <string.h>
#include <stdio.h>
int main() {
  char str[80];
  const char delimiters[5] = " -|."; 
  char *token, *pos;
  strcpy(str, "This   is-an|example-program.");
  pos = str;
  token = strsep(&pos, delimiters);
  while( token != NULL ) {
    printf( " %s\n", token );
    token = strsep(&pos, delimiters);
  }
}
