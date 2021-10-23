/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-27 19:38:38
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.27\d.cpp
 * @LastEditTime: 2021-08-27 23:19:21
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;
const int N = 1e5 + 10;

LL a[N], b[N], c[N], d[N]; 
signed main()
{
    IOS;
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        c[i] = c[i - 1] + a[i];
    }
    for(int i = 1; i <= n; ++ i){
        cin >> b[i];
        d[i] = d[i - 1] + b[i];
    }
    LL mx = 0, mn = 0;
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        if(c[i + k - 1] - c[i - 1] > mx){
            ans = i;
            mx = c[i + k - 1] - c[i - 1];
            mn = d[i + k - 1] - d[i - 1];
        }
        if(c[i + k - 1] - c[i - 1] == mx){
            if(d[i + k - 1] - d[i - 1] < mn){
                ans = i;
                mn = d[i + k - 1] - d[i - 1];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}