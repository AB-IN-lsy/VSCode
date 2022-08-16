/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-13 10:48:01
 * @FilePath: \Acwing\3652\3652.cpp
 * @LastEditTime: 2022-08-13 10:58:06
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

signed main()
{
    IOS;
    int n;
    while (cin >> n)
    {
        vector<int> a(N), dp(N);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = max(a[i], dp[i - 1] + a[i]);
        }
        int ans = INT_MIN, r = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (dp[i] > ans) // 保证最左
            {
                ans = dp[i];
                r = i;
            }
        }
        if (ans < 0)
            printf("0 0 0\n");
        else
        {
            int sum = 0, l = 0;
            for (int i = r; i > 0; --i)
            {
                sum += a[i];
                if (sum == ans) // 保证最左
                    l = i;
            }
            printf("%lld %lld %lld\n", ans, l - 1, r - 1);
        }
    }
    return 0;
}