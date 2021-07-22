// Example on using XOR operation
#include <stdio.h>
#define blockSize 10
int main(int argc, char *argv[]) {
  FILE *file, *newFile; 
  char password[blockSize]="compsci210";
  char block[blockSize];
  int i, numBytes;

  // argv[1] is the name of the input file
  // argv[2] is the name of the output file
  file = fopen(argv[1], "rb");
  newFile = fopen(argv[2], "wb");

  // repeatedly read 10 bytes from the input file
  // and XOR the 10 bytes with the value in array password
  do {
    numBytes = fread(block, 1, blockSize, file);
    for (i=0; i<numBytes; i++) 
      block[i] = block[i]^password[i];
    // write the result of XOR to the output file
    fwrite(block, 1, numBytes, newFile);
  } while (numBytes == blockSize);
  fclose(newFile);
  fclose(file);
}
