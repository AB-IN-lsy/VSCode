/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-20 21:21:02
 * @FilePath: \Acwing\1249\1249.cpp
 * @LastEditTime: 2023-02-21 11:37:18
 */
#pragma GCC optimize(1)
#pragma GCC optimize(2) // 先开优化
#pragma GCC optimize(3, "Ofast", "inline")
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

int fa[N];

int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b))
        {
            fa[find(a)] = find(b);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (find(a) == find(b) ? "Yes\n" : "No\n");
    }
    return 0;
}