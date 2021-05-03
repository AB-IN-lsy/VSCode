/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-08 20:28:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-05-03 13:05:35
 */
#include<bits/stdc++.h>
using namespace std;
#define ll                          long long
#define ull                         unsigned long long
#define ld                          long double
#define db                          double
#define all(x)                      (x).begin(),(x).end()
#define MP                          make_pair
#define PB                          emplace_back
#define SZ(X)                       ((int)(X).size())   
#define mset(s, _)                  memset(s, _, sizeof(s))
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl                        "\n"
#define forn(i, l, r)                for (int i = l; i <= r; i++)
const int INF = 0x3f3f3f3f;

void solve(){
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n);
    vector <ll> b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    sort(all(a));
    sort(all(b));
    ll ans = 0, j = n - 1;
    forn(i, 0, n - 1){
       if(a[i] + b[j] >= k) ans ++, j --;
    }
    cout << ans << endl;
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