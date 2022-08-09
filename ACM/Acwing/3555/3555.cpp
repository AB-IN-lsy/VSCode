/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-04 09:00:27
 * @FilePath: \Acwing\3555\3555.cpp
 * @LastEditTime: 2022-08-04 09:29:12
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1], depth(n + 1), st(n + 1);
    vector<vector<int>> fa(n + 1, vector<int>(11));
    for (int i = 1; i <= n; ++i)
    {
        int ls, rs;
        cin >> ls >> rs;
        if (ls != -1)
            g[i].push_back(ls);
        if (rs != -1)
            g[i].push_back(rs);
    }

    function<void(int)> bfs = [&](int root) {
        queue<int> q;
        q.push(root);

        //初始化depth
        depth[0] = 0; // 哨兵
        depth[root] = 1;
        st[root] = 1;

        while (SZ(q))
        {
            auto t = q.front();
            q.pop();
            for (auto v : g[t])
            {
                if (!st[v])
                {
                    st[v] = 1;
                    depth[v] = depth[t] + 1;
                    fa[v][0] = t;
                    for (int k = 1; k <= 10; ++k)
                    {
                        fa[v][k] = fa[fa[v][k - 1]][k - 1];
                    }
                    q.push(v);
                }
            }
        }
    };

    function<int(int, int)> lca = [&](int a, int b) {
        if (depth[a] < depth[b])
            swap(a, b);
        for (int k = 10; k >= 0; --k)
            if (depth[fa[a][k]] >= depth[b])
                a = fa[a][k];
        if (a == b)
            return a;
        for (int k = 10; k >= 0; --k)
        {
            if (fa[a][k] != fa[b][k])
            {
                a = fa[a][k];
                b = fa[b][k];
            }
        }
        return fa[a][0];
    };

    bfs(1);

    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        cout << depth[x] + depth[y] - 2 * depth[lca(x, y)] << '\n';
    }

    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}