/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-08 20:28:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-14 12:05:49
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

vector < int > v[200];
int f(int n){
    int ans = 0;
    while(n){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
int n;
void solve(){
    cin >> n;
    ll ans = INF, a;
    forn(i, 1, 100000){
        a = f(i);
        v[a].PB(i);
    }
    forn(i, 1, 100){
        if(SZ(v[i]) >= n){
            ll tmp = 0;
            int b = SZ(v[i]);
            int mn = min(b, n);
            forn(j, 0, mn - 1){
                tmp += v[i][j];
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans;
}

int main()
{
    IOS;
    solve();
    return 0;
}