/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-28 18:53:47
 * @FilePath: \Acwing\88cp\c.cpp
 * @LastEditTime: 2023-01-28 19:52:12
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e4 + 10, INF = 0x3f3f3f3f;

int dp[N][5]; // 代表第i天干第j件事情的休息时间
int n;

signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        dp[i][0] = min(dp[i - 1][2], min(dp[i - 1][0], dp[i - 1][1])) + 1;
        if (x == 0)
        {
            dp[i][1] = dp[i][2] = INF;
        }
        if (x == 1 || x == 3)
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]);
        else
            dp[i][2] = INF;
        if (x == 2 || x == 3)
            dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]);
        else
            dp[i][1] = INF;
    }
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);
    return 0;
}