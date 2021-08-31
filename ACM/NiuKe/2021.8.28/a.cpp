/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-28 12:14:05
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.28\a.cpp
 * @LastEditTime: 2021-08-28 15:45:26
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

signed main()
{
    IOS;
    int t;
    cin >> t;
    while(t --){
        LL n, ans = 0;
        cin >> n;
        LL qi = (n + 1) / 3;
        if(!(qi & 1)) qi += 1;
        ans += (n - qi) / 2 + 1;
        ans += n / 2;
        if(n & 1) ans += 1;
        cout << ans << '\n';
    }   
    return 0;
}