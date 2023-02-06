#pragma GCC optimize(1)
#pragma GCC optimize(2) // 先开优化
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

int dp[N], v[N], V, w[N], sum;

void solve()
{
    int n, V;
    scanf("%d%d", &n, &V);

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &v[i]);
        v[i] += i;
        w[i] = 1;
        sum += w[i];
    }
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
        if (dp[i] <= V)
        {
            printf("%d\n", i); // 输出最多获利
            return;
        }
    }

    return;
}

signed main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}