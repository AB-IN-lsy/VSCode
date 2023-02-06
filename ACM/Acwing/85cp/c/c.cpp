/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-02 18:39:23
 * @FilePath: \Acwing\85cp\c\c.cpp
 * @LastEditTime: 2023-02-02 19:18:19
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

const int N = 100, INF = 0x3f3f3f3f;

int fa[N], n, m;

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

signed main()
{
    IOS;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;

    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (find(x) != find(y))
            fa[find(x)] = find(y);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (fa[i] == i)
            cnt++;
    }

    cout << (int)pow(2, n - cnt);
    return 0;
}