/*
*  @Copyright (C) 2021 NEFU AB_IN. All rights reserved.
*  @FileName:part1.c
*  @Author:NEFU AB_IN
*  @Date:2021.06.18
*  @Description:https://blog.csdn.net/qq_45859188
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *file_in, *file_out;
    file_in = fopen(argv[1], "r");
    file_out = fopen(argv[2], "w");
    int x, y;
    while(fscanf(file_in, "%2x%2x", &x, &y) != EOF){
        fprintf(file_out, "%c%c", x, y);
    }
    fclose(file_in);
    fclose(file_out);
    return 0;
}
