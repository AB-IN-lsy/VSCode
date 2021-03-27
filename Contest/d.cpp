/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-03-08 20:28:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-26 00:27:39
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

const int N = 1e6 + 10;
ll a[N];
void solve(){
    int n;
    cin >> n;
    vector <int> v;
    vector <int> v1;
    unordered_map <ll, int> mp;
    forn(i ,1, n) cin >> a[i], mp[a[i]] ++;
    for(auto [a, b] : mp){
        v.PB(b);
    }
    sort(v.begin(), v.end());
    unordered_map <ll, int> ct;

    int sz = SZ(v);

    if(count(v.begin(), v.end(), 1) == sz){
        cout << sz % 2 << endl;
        return;
    }
    for(int i = 0; i < sz; i++){
        if(i + 1 > sz) break;
        if(v[i] == v[i + 1]){
            ct[v[i]] = 1;
        }
        if(v[i] != v[i + 1] && ct[v[i]] == 0){
            v1.PB(v[i]);
            ct[v[i]] = 1;
        }
    }
    if(ct[v[sz - 1]] == 0) v1.PB(v[sz - 1]);

    if(v1.size() >= 3) cout << 0 << endl;
    else if(v1.size() == 1) cout << v1[0] << endl;
    else if(v1.size() == 2) cout << abs(v1[0] - v1[1]) << endl;
    else cout << 0 << endl;
}

int main()
{
    int t;
    IOS;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}