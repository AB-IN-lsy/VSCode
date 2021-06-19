#include <stdio.h>
int main(int argc, char *argv[]) {
  FILE *file;
  int i,numBytes;
  unsigned char bytes[2];
  file = fopen(argv[1],"r");
  while (1) {
    numBytes = fread(bytes, 1, 2, file);
    if (numBytes == 0) break;
    for (i=0; i<numBytes; i++)
      printf("%02x",bytes[i]);
    printf("\n");
  }
  fclose(file);
}
