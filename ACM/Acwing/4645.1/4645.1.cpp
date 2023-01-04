/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-03 12:40:32
 * @FilePath: \Acwing\4645.1\4645.1.cpp
 * @LastEditTime: 2023-01-03 12:42:01
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

#undef N
const int N = 1e5 + 10;
int dp[N], n, m, k;

// #undef int

signed main()
{
    IOS;
    cin >> n >> m >> k;
    unordered_map<int, int> pre;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        dp[i] = max(dp[i - 1], pre[x ^ k]);
        pre[x] = i;
    }

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << (dp[r] >= l ? "yes" : "no") << '\n';
    }

    return 0;
}