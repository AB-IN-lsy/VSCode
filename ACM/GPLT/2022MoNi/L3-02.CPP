/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-18 22:03:11
 * @FilePath: \ACM\GPLT\2022MoNi\L3-02.CPP
 * @LastEditTime: 2022-04-18 22:50:42
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e4, M = 1e5;
int dp[M], v[N], w[N];

signed main()
{
    int n, m, sum = 0;
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &v[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &w[i]), sum += w[i];

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = sum; j >= w[i]; --j)
        {
            dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    for (int i = sum; i >= 0; --i)
    {
        if (dp[i] <= m)
        {
            printf("%lld", i);
            return 0;
        }
    }
    return 0;
}