/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-17 13:29:28
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-17 19:57:04
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

int main()
{
    IOS;
    int n, x;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        cout << x % 15 << " ";
    }
    return 0;
}