/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-29 23:25:32
 * @FilePath: \ACM\CF\2021.9.24\c.cpp
 * @LastEditTime: 2021-09-30 00:00:59
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
const int INF = 0x3f3f3f3f;

int n;
const int N = 3e6 + 10;
LL a[N], sum[N], dp[N][2];

signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = a[i] ^ sum[i - 1];
    }
    LL ans = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        ans += dp[sum[i]][i & 1];
        dp[sum[i]][i & 1]++;
    }
    cout << ans << '\n';
    return 0;
}