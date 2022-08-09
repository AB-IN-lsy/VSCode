/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-04 09:51:49
 * @FilePath: \Acwing\1172\1172.cpp
 * @LastEditTime: 2022-08-04 10:05:40
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
const int N = 4e4 + 10;

signed main()
{
    IOS;
    int n, root;
    cin >> n;
    vector<int> g[N], depth(N), st(N);
    vector<vector<int>> fa(N, vector<int>(16));
    for (int i = 1; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (b == -1)
            root = a;
        else
            g[a].push_back(b), g[b].push_back(a);
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
                    for (int k = 1; k <= 15; ++k)
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
        for (int k = 15; k >= 0; --k)
            if (depth[fa[a][k]] >= depth[b])
                a = fa[a][k];
        if (a == b)
            return a;
        for (int k = 15; k >= 0; --k)
        {
            if (fa[a][k] != fa[b][k])
            {
                a = fa[a][k];
                b = fa[b][k];
            }
        }
        return fa[a][0];
    };

    bfs(root);

    int m;
    cin >> m;

    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        int p = lca(x, y);
        if (p == x)
            cout << "1\n";
        else if (p == y)
            cout << "2\n";
        else
            cout << "0\n";
    }

    return 0;
}