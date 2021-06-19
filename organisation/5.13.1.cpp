/*
*  @Copyright (C) 2021 NEFU AB_IN. All rights reserved.
*  @FileName:5.13.1.cpp
*  @Author:NEFU AB_IN
*  @Date:2021.05.24
*  @Description:https://blog.csdn.net/qq_45859188
*/

#include <bits/stdc++.h>
using namespace std;
#define LL                    long long
#define ULL                   unsigned long long
#define SZ(X)                 ((int)(X).size())
#define IOS                   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef pair<int , int>       PII;

int main(){
    IOS;
    unsigned char a = 0x3c;
    unsigned char b, c;
    printf("before: %x\n", a);
    b = a & 0xf0;
    c = a & 0x0f;
    a = (b >> 4) | (c << 4);
    printf("after: %x\n", a);
    return 0;
}
