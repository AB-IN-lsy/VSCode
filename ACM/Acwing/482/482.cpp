/*
 * @Author: NEFU AB-IN
 * @Date: 2023-09-07 17:07:57
 * @FilePath: \Acwing\482\482.cpp
 * @LastEditTime: 2023-09-07 18:35:39
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int a[N], f[N], g[N];

signed main()
{
    // freopen("Tests/input_1.txt", "r", stdin);
    IOS;

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        f[i] = 1;
        for (int j = 1; j < i; ++j)
        {
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
        }
    }

    for (int i = n; i; --i)
    {
        g[i] = 1;
        for (int j = n; j > i; --j)
            if (a[j] < a[i])
                g[i] = max(g[i], g[j] + 1);
    }

    int mx = 0;
    for (int i = 1; i <= n; ++i)
    {
        mx = max(mx, f[i] + g[i] - 1);
    }

    cout << n - mx;

    return 0;
}