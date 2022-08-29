/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-23 09:44:37
 * @FilePath: \Acwing\4405\4405.cpp
 * @LastEditTime: 2022-08-23 09:56:20
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            int l = 1, r = 1, sum = 0;
            while (l <= m && r <= m)
            {
                sum += a[j][r] - a[i - 1][r];
                while (sum > k)
                {
                    sum -= a[j][l] - a[i - 1][l];
                    ++l;
                }
                res += r - l + 1; // 左边界可以从l取到r
                ++r;
            }
        }
    }
    cout << res << '\n';
    return 0;
}