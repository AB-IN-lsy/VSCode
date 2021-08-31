/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-27 19:01:40
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.27\a.cpp
 * @LastEditTime: 2021-08-27 19:13:09
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
    int a, b, h, k;
    cin >> a >> h >> b >> k;
    int guang = (k + a - 1) / a;
    int duili = (h + b - 1) / b;
    LL ans = min(guang, duili) * (a + b);
    if(guang > duili){
        ans += b * 10;
    }  
    else if(guang < duili){
        ans += a * 10;
    }
    cout << ans << '\n';
    return 0;
}