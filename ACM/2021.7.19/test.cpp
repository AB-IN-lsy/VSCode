/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-22 00:21:21
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-22 00:32:49
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

class a{
public:
    int name;
    a(int x):name(x) {};

    void Test_CPP(){
        printf("CPP:%d \n", this->name);
    }

};

int main()
{
    IOS;
    a(1);
    return 0;
}