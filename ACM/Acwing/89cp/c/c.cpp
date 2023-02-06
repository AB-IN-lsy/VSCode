/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-04 18:58:52
 * @FilePath: \Acwing\89cp\c\c.cpp
 * @LastEditTime: 2023-02-04 19:32:40
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

const int N = 1e7 + 10, INF = 0x3f3f3f3f;

int dp[N];

signed main()
{
    IOS;
    int n, x, y;
    cin >> n >> x >> y;

    for (int i = 1; i <= n; ++i)
    {
        // dp[i] = min(dp[i - 1] + x, dp[i + 1] + x, dp[i / 2] + y);
        dp[i] = dp[i - 1] + x;
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + y);

        dp[i + 1] = dp[i] + x;
        if ((i + 1) % 2 == 0)
            dp[i + 1] = min(dp[i + 1], dp[(i + 1) / 2] + y);

        dp[i] = min(dp[i], dp[i + 1] + x);
    }
    cout << dp[n];
    return 0;
}