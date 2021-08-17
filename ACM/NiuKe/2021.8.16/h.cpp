/*
 * @Description: E
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-16 13:33:01
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.16\h.cpp
 * @LastEditTime: 2021-08-16 13:50:58
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

int n;
int check(int x){
    int cnt = 0;
    while(x){
        cnt += (x % 2);
        x = x >> 1;
    }
    return cnt & 1 ? 1 : 0;
}

int main()
{
    IOS;
    cin >> n;
    for(int i = 0; i < (1 << n); ++ i){
        cout << check(i);
    }
    return 0;
}