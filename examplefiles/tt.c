/*
*  @Copyright (C) 2021 NEFU AB_IN. All rights reserved.
*  @FileName:part2.c
*  @Author:NEFU AB_IN
*  @Date:2021.06.18
*  @Description:https://blog.csdn.net/qq_45859188
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char* strrev(char *str)
{
    char *p1, *p2;
    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

char* change(int x){
    char tmp[3];
    int cnt = 0;
    while(x > 0){
        if(x & 1) tmp[cnt++] = '1';
        else tmp[cnt++] = '0';
        x = x >> 1;
    }
    int p = strlen(tmp);
    if(p != 3){
        for(int i = 1; i <= (3 - p); i ++) 
            tmp[cnt++] = '0';
    }
    strrev(tmp);
    char* ans = tmp;
    return ans;
}

char* con2_10(char* str){
    int cnt = 0;
    int p = 8;
    int tmp = 0;
    char ans[4];
    for(int i = 0; i <= 15; i ++){
        tmp += p * (*(str + i) - '0');
        p /= 2;
        if(p == 0){
            p = 8;
            ans[cnt++] = tmp + '0';
            tmp = 0;
        }
    }
    char* ans1 = ans;
    return ans1;
}

int main(int argc, char *argv[]){
    printf("%s", change(2));
    return 0;
}
