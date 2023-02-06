/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-03 22:35:26
 * @FilePath: \CF\1791\e\e.cpp
 * @LastEditTime: 2023-02-04 11:07:18
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

int dp[N][2], a[N];

void solve()
{
    memset(a, 0, sizeof a);
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    dp[1][0] = a[1], dp[1][1] = -a[1];
    dp[2][0] = a[1] + a[2], dp[2][1] = -a[1] - a[2];
    for (int i = 3; i <= n; ++i)
    {
        dp[i][0] = a[i] + max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = -a[i] + max(dp[i - 1][0] - 2 * a[i - 1], dp[i - 1][1] + 2 * a[i - 1]);
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';
    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}