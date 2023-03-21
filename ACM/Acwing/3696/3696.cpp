/*
 * @Author: NEFU AB-IN
 * @Date: 2023-03-01 23:23:00
 * @FilePath: \Acwing\3696\3696.cpp
 * @LastEditTime: 2023-03-01 23:58:06
 */
// #pragma GCC optimize(1)
// #pragma GCC optimize(2) // 先开优化
// #pragma GCC optimize(3, "Ofast", "inline")
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

const int N = 3e5 + 10, INF = 0x3f3f3f3f;

int deg[N];
bool st[N], vis[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    memset(st, 0, (n + 1));
    memset(deg, 0, (n + 1) * 4);
    memset(vis, 0, (n + 1));

    vector<int> g[n + 1], g1[n + 1];

    for (int i = 1; i <= m; ++i)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t)
        {
            g1[a].push_back(b);
            deg[b]++;
        }
        else
        {
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!deg[i])
            q.push(i);
    }
    if (!SZ(q))
    {
        cout << "NO\n";
        return;
    }
    int cnt = 0;
    while (SZ(q))
    {
        auto u = q.front();
        q.pop();
        if (st[u] || deg[u])
            continue;

        for (auto &v : g[u])
        {
            if (!st[v])
            {
                g1[u].push_back(v);
                deg[v]++;
            }
        }
        st[u] = true; // 表示已经释放出去了
        cnt++;
        for (auto &v : g1[u])
        {
            if (!--deg[v])
            {
                q.push(v);
            }
        }
    }
    if (cnt != n)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (auto &v : g1[u])
        {
            cout << u << " " << v << '\n';
            if (!vis[v])
                dfs(v);
        }
    };

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
            dfs(i);
    }
    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}