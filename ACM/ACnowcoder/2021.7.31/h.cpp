/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-31 12:08:17
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-31 12:11:00
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
    int n, m, flag = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j ++){
            if(flag) cout << 1, flag = 0;
            else cout << 0, flag = 1;
        }
        cout << endl;
    }
    return 0;
}