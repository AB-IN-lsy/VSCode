/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-14 18:59:46
 * @FilePath: \Acwing\86cp\c.cpp
 * @LastEditTime: 2023-01-14 19:32:58
 */
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

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int n;
int a[N], dp[N];
int mn = INF, mx = -INF;

signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[x]++;
        mx = max(mx, x);
        mn = min(mn, x);
    }

    for (int i = mn; i <= mx; ++i)
    {
        if (i == 1)
            dp[i] = max(dp[i - 1], a[i] * i);
        else
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i] * i);
    }

    cout << dp[mx];

    return 0;
}