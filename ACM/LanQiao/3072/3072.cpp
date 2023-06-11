/*
 * @Author: NEFU AB-IN
 * @Date: 2023-06-09 21:17:06
 * @FilePath: \LanQiao\3072\3072.cpp
 * @LastEditTime: 2023-06-09 21:38:56
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

const int N = 510, INF = 0x3f3f3f3f;
int dp[N][N], res;

int f(int n)
{
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            dp[i][j] = dp[i - j][j] + dp[i - j][j - 1];
    }
    int ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        ans += dp[n][i];
    }
    return ans;
}
signed main()
{
    IOS;
    int n;
    cin >> n;
    cout << f(n) << '\n';
    return 0;
}
