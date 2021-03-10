/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-08 20:28:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-10 21:07:52
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

unordered_map <ll, int> a;

void solve(){
    ll n, k, x, mx = 0;
    cin >> n >> k;
    a.clear();
    forn(i, 1, n) {
        cin >> x;
        a[x] = 1;
        mx = max(mx, x);
    }
    if(k == 0){
        cout << n << endl;
        return;
    }
    ll me = mx + 1;
    forn(i, 0, mx) {
        if(!a[i]){
            me = i;
            break;
        }
    }
    ll ans = 0;
    if(me == mx + 1) ans = k;
    else {
        if( a[ceil( (ld) (me + mx) / 2)] == 0 ) ans = 1;
    };
    cout << n + ans << endl;
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