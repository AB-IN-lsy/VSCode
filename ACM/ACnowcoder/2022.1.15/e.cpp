/*
 * @Author: NEFU AB-IN
 * @Date: 2022-01-15 13:38:35
 * @FilePath: \ACM\ACnowcoder\2022.1.15\e.cpp
 * @LastEditTime: 2022-01-15 13:46:19
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e4 + 10;

int c[N], w[N], dp[N];
int n, v;

signed main()
{
    IOS;

    cin >> n >> v;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i] >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = c[i]; j <= v; j++)
        {
            dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
        }
    }

    cout << dp[v] << '\n';
    return 0;
}