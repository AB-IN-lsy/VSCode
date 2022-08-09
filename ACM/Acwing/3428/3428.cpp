/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-04 17:01:35
 * @FilePath: \Acwing\3428\3428.cpp
 * @LastEditTime: 2022-08-06 01:53:03
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    int m, n;
    while (cin >> m >> n)
    {
        vector<vector<int>> dp(11, vector<int>(11, 0));
        // m个放进n个盘子
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
            }
        }
        int res = 0;
        for (int j = 1; j <= n; j++)
        {
            res += dp[m][j];
        }
        cout << res << '\n';
    }
    return 0;
}