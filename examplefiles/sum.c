/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-06-19 19:02:44
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-06-19 20:32:58
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  if(argc != 3){
	printf("usage :%s operand1 oprand2\n", argv[0]);
  }
  else{
	  int operand1, operand2;
	  char *ptr;
	  operand1 = strtol(argv[1], &ptr, 10);
	  operand2 = strtol(argv[2], &ptr, 10);
	  printf("%d + %d = %d \n", operand1, operand2, operand1 + operand2);
  }
  return 0;
}
