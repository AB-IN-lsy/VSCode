/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-08 20:28:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-25 23:27:50
 */
#include<bits/stdc++.h>
using namespace std;
#define ll                          long long
#define ull                         unsigned long long
#define ld                          long double
#define db                          double
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define MP                          make_pair
#define PB                          emplace_back
#define SZ(X)                       ((int)(X).size())   
#define mset(s, _)                  memset(s, _, sizeof(s))
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl                        "\n"
#define forn(i, l, r)                for (int i = l; i <= r; i++)
typedef pair<int, int>               pii;
typedef pair<ll, ll>                 pll;
const int INF = 0x3f3f3f3f;

const int N = 100;

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int dp[N][N], mx = 0;
    mset(dp, 0);
    for(int i = 0; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            if(s1[i] == s2[j]){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                mx = max(mx, dp[i][j]);
            }
        }
    }
    cout << s1.size() + s2.size() - 2 * mx << endl;
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}