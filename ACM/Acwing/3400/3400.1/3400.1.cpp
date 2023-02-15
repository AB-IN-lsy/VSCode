/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-01 12:23:52
 * @FilePath: \Acwing\3400.1\3400.1.cpp
 * @LastEditTime: 2023-01-01 12:25:37
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
const int N = 1e6 + 10;

// #undef int

signed main()
{
    IOS;
    int n, k, ans = 0;
    cin >> n >> k;

    vector<int> dp(N);
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i / 10] + (i % 10 == k);
        ans += dp[i];
    }
    cout << ans;
    return 0;
}