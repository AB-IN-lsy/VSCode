/*
*  @Copyright (C) 2021 NEFU AB_IN. All rights reserved.
*  @FileName:part1.c
*  @Author:NEFU AB_IN
*  @Date:2021.06.18
*  @Description:https://blog.csdn.net/qq_45859188
*/

#include <stdio.h>
#include <string.h>
#define LL                    long long
#define ULL                   unsigned long long
int main(int argc, char *argv[]){
    FILE *file_in, *file_out;
    file_in = fopen("t1.txt", "r");
    file_out = fopen("t1.obj", "w");
    int cnt = 0, numBytes;
    char bytes[2];
    char c;
    do{
        numBytes = fread(bytes, 1, 2, file_in);
        cnt += numBytes;
        if(numBytes == 0) break;
        fwrite(bytes, 1, 2, file_out);
        if(cnt == 4) {
            c = fgetc(file_in);
            cnt = 0;
        }
    }while(1);
    fclose(file_in);
    fclose(file_out);
    return 0;
}
