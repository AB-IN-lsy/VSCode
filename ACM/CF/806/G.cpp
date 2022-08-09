// Problem: G. Good Key, Bad Key
// Contest: Codeforces Round #806 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-07-12 22:36:40
// URL: https://codeforces.com/contest/1703/problem/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e5 + 10;

int dp[N][41];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 40; ++j)
            dp[i][j] = -INF;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 40; ++j)
        {
            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (a[i] >> j));
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + a[i] - m;
            else
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i] >> j) - m);
            if (j >= 32)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    int ans = -INF;
    for (int j = 0; j < 40; ++j)
    {
        ans = max(ans, dp[n][j]);
    }
    cout << ans << '\n';
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}