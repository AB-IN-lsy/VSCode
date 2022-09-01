/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-31 20:50:12
 * @FilePath: \GPLT\A1007\A1007.cpp
 * @LastEditTime: 2022-08-31 21:18:47
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
    cin >> n;
    int cnt = 0;
    vector<int> a(N), dp(N);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] < 0)
            cnt++;
    }
    if (cnt == n)
    {
        cout << 0 << " " << a[1] << " " << a[n];
        return 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
    }
    int mx = 0, r = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (mx < dp[i])
        {
            mx = dp[i];
            r = i;
        }
    }
    int l = r, tmp = mx;
    for (int i = r; i >= 1; --i)
    {
        mx -= a[i];
        if (mx == 0)
            l = i;
    }
    cout << tmp << " " << a[l] << " " << a[r];
    return 0;
}