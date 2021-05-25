/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-08 20:28:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-04-10 19:38:49
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

void solve(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.length(); i++) if(s[i] == '.' && s[i - 1] == '.') ans ++;
    while(m --){
        int x;
        char c;
        cin >> x >> c;
        x -= 1;
        if(s[x] == '.' && c != '.') ans -= (s[x - 1] == '.') + (s[x + 1] == '.');
        if(s[x] != '.' && c == '.') ans += (s[x - 1] == '.') + (s[x + 1] == '.');
        s[x] = c;
        cout << ans << endl;
    }
}

int main()
{
    IOS;
    solve();
    return 0;
}