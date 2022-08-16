/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-13 12:36:33
 * @FilePath: \Acwing\4518\4518.cpp
 * @LastEditTime: 2022-08-13 15:10:31
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

#define lowbit(x) x & -x

signed main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> a(N), dp(N), cost(3), tr(366);

    auto add = [&](int x, int d) {
        for (int i = x; i < 366; i += lowbit(i))
            tr[i] += d;
    };
    auto query = [&](int x) {
        int res = 0;
        for (int i = x; i > 0; i -= lowbit(i))
            res += tr[i];
        return res;
    };
    auto get = [&](int i, int t) {
        if (a[i] - t <= 0)
            return 0LL;
        else
            return i - (query(a[i]) - query(a[i] - t));
    };

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        add(a[i], 1);
    }

    for (int i = 0; i < 3; ++i)
        cin >> cost[i];

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + cost[0];
        dp[i] = min(dp[i], dp[get(i, 7)] + cost[1]);
        dp[i] = min(dp[i], dp[get(i, 30)] + cost[2]);
    }
    cout << dp[n];
    return 0;
}