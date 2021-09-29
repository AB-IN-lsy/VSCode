/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-24 21:29:09
 * @FilePath: \ACM\CF\2021.9.24\b.cpp
 * @LastEditTime: 2021-09-29 23:02:03
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
LL a[N], b[N], c[N], dp[N];

void solve()
{
    // construct the minus array
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 >= n)
            break;
        b[++cnt1] = a[i + 1] - a[i];
    }
    for (int i = 1; i < n; i += 2)
    {
        if (i + 1 >= n)
            break;
        c[++cnt2] = a[i] - a[i + 1];
    }
    // start dp function 1
    dp[0] = 0;
    for (int i = 1; i <= cnt1; ++i)
    {
        dp[i] = max(dp[i - 1] + b[i], b[i]);
    }
    LL mx = dp[1];
    for (int i = 1; i <= cnt1; ++i)
    {
        mx = max(mx, dp[i]);
    }
    // start dp function 2
    dp[0] = 0;
    for (int i = 1; i <= cnt2; ++i)
    {
        dp[i] = max(dp[i - 1] + c[i], c[i]);
    }
    for (int i = 1; i <= cnt2; ++i)
    {
        mx = max(mx, dp[i]);
    }
    LL ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
            ans += a[i];
    }
    cout << max(ans, ans + mx) << '\n';
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