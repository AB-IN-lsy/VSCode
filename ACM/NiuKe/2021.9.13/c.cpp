/*
 * @Author: NEFU AB_IN
 * @Date: 2021-09-14 20:04:50
 * @FilePath: \Vscode\ACM\NiuKe\2021.9.13\c.cpp
 * @LastEditTime: 2021-09-14 20:19:10
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
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int N = 110, M = 1e5 + 10;
bool dp[N][M << 1];
int n, sum, w[N];
signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i];
        sum += w[i];
    }
    dp[0][M] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = -sum; j <= sum; ++j)
        {
            dp[i][j + M] = dp[i - 1][j + M];
            if (j - w[i] >= -sum)
                dp[i][j + M] |= dp[i - 1][j - w[i] + M];
            if (j + w[i] <= sum)
                dp[i][j + M] |= dp[i - 1][j + w[i] + M];
        }
    }
    int ans = 0;
    for (int i = 1; i <= sum; ++i)
    {
        if (dp[n][i + M])
            ans++;
    }
    cout << ans << '\n';
    return 0;
}