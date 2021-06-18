/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2020-12-10 10:46:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-06-18 15:48:00
 */
#include <stdio.h>
int main(int argc, char *argv[]) {
  FILE *file;
  int i,numBytes;
  unsigned char bytes[2];
  file = fopen("t1.txt","r");
  while (1) {
    numBytes = fread(bytes, 1, 2, file);
    if (numBytes == 0) break;
    for (i=0; i<numBytes; i++)
      printf("%02x",bytes[i]);
    printf("\n");
  }
  fclose(file);
}