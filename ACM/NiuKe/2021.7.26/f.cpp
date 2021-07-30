/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-26 12:11:17
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-30 02:29:30
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

int main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    if((n + m) & 1) puts("Alice");
    else puts("Bob");   
    return 0;
}