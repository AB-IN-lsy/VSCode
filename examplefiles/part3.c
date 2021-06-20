/*
*  @Copyright (C) 2021 NEFU AB_IN. All rights reserved.
*  @FileName:part3.c
*  @Author:NEFU AB_IN
*  @Date:2021.06.20
*  @Description:https://blog.csdn.net/qq_45859188
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* strrev(char *str){
    char *p1, *p2;
    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
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
            char c;
            if(tmp >= 10) ans[cnt++] =  'a' + tmp - 10;
            else ans[cnt++] = tmp + '0';
            tmp = 0;
        }
    }
    char* ans1 = ans;
    return ans1;
}

char* change3(int x){
    char tmp[3];
    int cnt = 0;
    if(x == 0){
        return "000";
    }
    while(x > 0){
        if(x & 1) tmp[cnt++] = '1';
        else tmp[cnt++] = '0';
        x = x >> 1;
    }
    int p = strlen(tmp);
    for(int i = 1; i <= (3 - p); i ++) tmp[cnt++] = '0';
    strrev(tmp);
    char* ans = tmp;
    return ans;
}

char* change5(int x){
    char tmp[5];
    int cnt = 0;
    if(x == 0){
        return "00000";
    }
    while(x > 0){
        if(x & 1) tmp[cnt++] = '1';
        else tmp[cnt++] = '0';
        x = x >> 1;
    }
    int p = strlen(tmp);
    for(int i = 1; i <= (5 - p); i ++) tmp[cnt++] = '0';
    strrev(tmp);
    char* ans = tmp;
    return ans;
}

int main(int argc, char *argv[]){
    FILE *file_in, *file_out;
    file_in = fopen(argv[1], "r");
    file_out = fopen(argv[2], "w");
    char delimiters[3] = " ,";
    char line[100];
    char ans[100];
    char c;
    int x, y;
    char* linePtr;
    do{
        linePtr = line;
        memset(linePtr, 0, 100);
        do{
            c = fgetc(file_in);
            if(c != '\n' && c != EOF) *(linePtr++) = c;
            else break;
        }while(1);
        if(c == EOF) break;
        else{
            char* pos = line;
            char* token;
            token = strsep(&pos, delimiters);
            while(token != NULL){
                if(strstr(token, ".orig") == token){
                    token = strsep(&pos, delimiters);
                    sscanf(token + 1, "%2x%2x", &x, &y);
                    fprintf(file_out, "%c%c", x, y);
                    break;
                }
                if(strstr(token, ".end") == token) break;
                if(strstr(token, "add") == token){
                    char tmp[100] = "0001";
                    char* ptr;
                    for(int i = 1; i <= 3; i ++){
                        token = strsep(&pos, delimiters);
                        if(i == 3) {
                            if(*(token) == 'r') {
                                strcat(tmp, "000");
                                int p = strtol(token + 1, &ptr, 10);
                                strcat(tmp, change3(p));
                            }
                            if(*(token) == '#') {
                                strcat(tmp, "1");
                                if(*(token + 1) == '-'){
                                    char* reverse = change5(strtol(token + 2, &ptr, 10) - 1);
                                    for(int i = 0; i <= 4; i ++){
                                        if(*(reverse + i) == '0') *(reverse + i) = '1';
                                        else *(reverse + i) = '0';
                                    }
                                    strcat(tmp, reverse);
                                }
                                else{
                                    int p = strtol(token + 1, &ptr, 10);
                                    strcat(tmp, change5(p)); 
                                }
                                //printf("tmp : %s\n", tmp);
                            }
                            continue;
                        }
                        int p = strtol(token + 1, &ptr, 10);
                        strcat(tmp, change3(p));   
                    }
                    char* after = con2_10(tmp);
                    char real[4];
                    strcpy(real, after);
                    sscanf(real, "%2x%2x", &x, &y);
                    fprintf(file_out, "%c%c", x, y);
                }
                if(strstr(token, "and") == token){
                    char tmp[100] = "0101";
                    char* ptr;
                    for(int i = 1; i <= 3; i ++){
                        token = strsep(&pos, delimiters);
                        if(i == 3) {
                            if(*(token) == 'r') {
                                strcat(tmp, "000");
                                int p = strtol(token + 1, &ptr, 10);
                                strcat(tmp, change3(p)); 
                            }
                            if(*(token) == '#') {
                                strcat(tmp, "1");
                                if(*(token + 1) == '-'){
                                    char* reverse = change5(strtol(token + 2, &ptr, 10) - 1);
                                    for(int i = 0; i <= 4; i ++){
                                        if(*(reverse + i) == '0') *(reverse + i) = '1';
                                        else *(reverse + i) = '0';
                                    }
                                    strcat(tmp, reverse);
                                }
                                else{
                                    int p = strtol(token + 1, &ptr, 10);
                                    strcat(tmp, change5(p)); 
                                }
                                //printf("tmp : %s\n", tmp);
                            }
                            continue;
                        }
                        int p = strtol(token + 1, &ptr, 10);
                        strcat(tmp, change3(p));   
                    }
                    char* after = con2_10(tmp);
                    char real[4];
                    strcpy(real, after);
                    sscanf(real, "%2x%2x", &x, &y);
                    fprintf(file_out, "%c%c", x, y);
                }
                if(strstr(token, "halt") == token){
                    char* tmp = "f025";
                    sscanf(tmp, "%2x%2x", &x, &y);
                    fprintf(file_out, "%c%c", x, y);
                    break;
                }
                token = strsep(&pos, delimiters);
            }
        }
    }while(1); 
    fclose(file_in);
    fclose(file_out);
    return 0;
}
