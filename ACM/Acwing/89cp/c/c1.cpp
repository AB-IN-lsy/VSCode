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

const int N = 2e7 + 10, INF = 0x3f3f3f3f;

int dp[N];

signed main()
{
    IOS;
    int n, x, y;
    cin >> n >> x >> y;
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i & 1)
            dp[i] = min(dp[(i + 1) / 2] + x + y, dp[i - 1] + x);
        else
            dp[i] = min(dp[i / 2] + y, dp[i - 1] + x);
    }
    cout << dp[n];
    return 0;
}