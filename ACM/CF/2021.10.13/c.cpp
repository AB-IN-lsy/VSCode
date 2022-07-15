/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-13 23:48:34
 * @FilePath: \ACM\CF\2021.10.13\c.cpp
 * @LastEditTime: 2021-10-13 23:54:01
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((LL)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
typedef pair<LL, LL> PII;
const LL INF = 0x3f3f3f3f;

const LL N = 1e6 + 10;
LL a[N];

void solve()
{
    LL n, k;
    cin >> n >> k;
    for (LL i = 1; i <= k; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + k, greater<LL>());
    LL m = 0, ans = 0;
    for (LL i = 1; i <= k; ++i)
    {
        LL xx = n - a[i];
        if (m + xx >= n)
        {
            cout << ans << '\n';
            return;
        }
        m += xx;
        ans += 1;
    }
    cout << ans << '\n';
}

signed main()
{
    IOS;
    LL t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}