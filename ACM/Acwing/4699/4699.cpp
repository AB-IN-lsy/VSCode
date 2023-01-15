/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-12 12:23:41
 * @FilePath: \Acwing\4699\4699.cpp
 * @LastEditTime: 2023-01-12 12:47:52
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
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), c(n + 1), mc(n + 1), cb(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    c[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        c[i] = c[i - 1] * a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        mc[i] = m % c[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        cb[i] = mc[i] - mc[i - 1];
        cout << cb[i] / c[i - 1] << " ";
    }

    return 0;
}