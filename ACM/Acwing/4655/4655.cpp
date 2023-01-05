/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-05 11:59:15
 * @FilePath: \Acwing\4655\4655.cpp
 * @LastEditTime: 2023-01-05 12:11:37
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
int n, m, a[N], b[N];

// #undef int

signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        int l, r;
        cin >> l >> r;
        b[l]++;
        b[r + 1]--;
    }
    for (int i = 0; i <= n; ++i)
    {
        b[i] += b[i - 1];
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans1 += (a[i] * b[i]);
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);

    for (int i = 1; i <= n; ++i)
    {
        ans2 += (a[i] * b[i]);
    }

    cout << ans2 - ans1;
    return 0;
}