// Problem: E. Mirror Grid
// Contest: Codeforces Round #806 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-07-12 22:36:38
// URL: https://codeforces.com/contest/1703/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 110;

char a[N][N];
int st[N][N];

void solve()
{
    int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", a[i] + 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            st[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (st[i][j])
                continue;
            // 统计1的个数
            int cnt1 = (a[i][j] == '1') + (a[n - j + 1][i] == '1') + (a[n - i + 1][n - j + 1] == '1') +
                       (a[j][n - i + 1] == '1');
            if (cnt1 >= 2)
                ans += (4 - cnt1);
            else
                ans += cnt1;

            st[i][j] = st[n - j + 1][i] = st[n - i + 1][n - j + 1] = st[j][n - i + 1] = 1;
        }
    }
    printf("%lld\n", ans);
    return;
}

signed main()
{
    int T;
    scanf("%lld", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}