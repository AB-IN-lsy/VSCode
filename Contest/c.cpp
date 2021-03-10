/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-08 20:28:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-10 21:37:04
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

ld d(ll x, ll y){
    return (ld) sqrt(x * x + y * y);
}

void solve(){
    int n;
    ll x, y;
    scanf("%d", &n);
    vector < ll > x1, y1;
    forn(i, 1, 2 * n){
        scanf("%lld%lld", &x, &y);
        x = abs(x);
        y = abs(y);
        if(x) x1.PB(x);
        if(y) y1.PB(y);
    }
    sort(x1.begin(), x1.end());
    sort(y1.begin(), y1.end());
    ld ans = 0;
    forn(i, 0, n - 1){
        ans += d(x1[i], y1[i]);
    }
    printf("%.18Lf\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t --){
        solve();
    }
    return 0;
}