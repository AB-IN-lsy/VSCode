/*
 * @Description: 
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-02-16 17:00:46
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-03-02 22:04:45
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
#define ls                          i << 1
#define rs                          i << 1 | 1
typedef pair<int, int>               pii;
typedef pair<ll, ll>                 pll;
const int INF = 0x3f3f3f3f;

const int N = 2e5 + 7;
int a[N], s[N], n, k, m[N];

bool check(int x){
    for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + (a[i] >= x ? 1 : -1);
    for(int i = 1; i <= n; i ++) m[i] = min(m[i - 1], s[i]);
    for(int i = k; i <= n; i ++) {
        if(s[i] - m[i - k] > 0) return true;
    }
    return false;
}

int main()
{
    IOS;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    } 
    int l = 1, r = n;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}