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

const int INF = 1E18;
const int N = 3e4 + 10;

bitset<N> b[N];

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 1);
    vector<int> g[n + 1];

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        deg[v] += 1;
    }

    // 找拓扑排序的头
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!deg[i])
            q.push(i);
    }
    // 拓扑排序，并记下拓扑排序
    vector<int> tops;
    while (SZ(q))
    {
        int u = q.front();
        q.pop();
        tops.push_back(u);
        for (auto v : g[u])
        {
            deg[v]--;
            if (deg[v] == 0)
            {
                q.push(v);
            }
        }
    }

    // 逆序遍历拓扑排序
    for (int i = n - 1; i >= 0; --i)
    {
        int u = tops[i];
        b[u].set(u); // 自己能到自己
        for (auto v : g[u])
        {
            b[u] |= b[v];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << b[i].count() << '\n';
    }

    return 0;
}