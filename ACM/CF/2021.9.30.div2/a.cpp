/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-30 17:58:25
 * @FilePath: \ACM\CF\2021.9.30.div2\a.cpp
 * @LastEditTime: 2021-09-30 18:49:15
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 1e6 + 10;
int a[N];
const LL mod = 1e9 + 7;
LL mul(LL x, LL y){return 1LL * x * y % mod;}
LL dec(LL x, LL y){return x >= y ? x - y : x + mod - y;}
LL add(LL x, LL y){return x + y >= mod ? x + y - mod : x + y;}
LL pmod(LL x) {return (x + mod) % mod;}

void solve()
{
    LL n;
    cin >> n;
    LL ans = 1;
    for (int i = 1; i <= (2 * n - 1); ++i)
    {
        ans = mul(ans, i);
    }
    cout << mul(ans, n) << '\n';
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}