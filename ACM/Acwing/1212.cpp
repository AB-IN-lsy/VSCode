/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-23 20:38:59
 * @FilePath: \ACM\Acwing\1212.cpp
 * @LastEditTime: 2022-03-23 20:58:14
 */
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 55, K = 15, C = 15, MOD = 1e9 + 7;

int dp[N][N][K][C];
// dp[i][j][p][q] 表示：在 (i, j) 这个点，拿了 p 个物品，这些物品中价值最大的是 q

int c[N][N];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> c[i][j];
            c[i][j] += 1; // 因为题目中说也有价值为0的物品，所以可以让价值整体偏移1
        }
    }
    dp[1][1][0][0] = 1;
    dp[1][1][1][c[1][1]] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int p = 0; p <= k; ++p)
            { //物品
                for (int q = 0; q < C; ++q)
                { //最大值

                    if (p > 0 && q == c[i][j])
                    {
                        for (int s = 0; s < c[i][j]; ++s)
                        {
                            dp[i][j][p][q] = (dp[i][j][p][q] + dp[i - 1][j][p - 1][s]) % MOD;
                            dp[i][j][p][q] = (dp[i][j][p][q] + dp[i][j - 1][p - 1][s]) % MOD;
                        }
                    }
                    dp[i][j][p][q] = (dp[i][j][p][q] + dp[i - 1][j][p][q]) % MOD;
                    dp[i][j][p][q] = (dp[i][j][p][q] + dp[i][j - 1][p][q]) % MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int q = 1; q < C; ++q)
    {
        ans = (ans + dp[n][m][k][q]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}