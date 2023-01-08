/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-08 17:39:34
 * @FilePath: \GPLT\A1034\A1034.cpp
 * @LastEditTime: 2023-01-08 18:30:36
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

struct sa
{
    int sz;
    string boss;

    bool operator<(const sa &t) const
    {
        return boss < t.boss;
    }
};

unordered_map<string, vector<string>> g;
unordered_map<string, int> degs, st;

signed main()
{
    IOS;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        string u, v;
        int w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        degs[u] += w;
        degs[v] += w;
    }

    function<void(string, vector<string> &)> dfs = [&](string u, vector<string> &nodes) {
        st[u] = 1;
        nodes.push_back(u);

        for (auto &v : g[u])
        {
            if (!st[v])
                dfs(v, nodes);
        }
        return;
    };

    vector<sa> ans;

    for (auto &[u, deg] : degs)
    {
        if (!st[u])
        {
            vector<string> nodes;
            dfs(u, nodes);

            int sum = 0;
            for (auto &node : nodes)
            {
                sum += degs[node];
            }
            sum /= 2;

            if (sum > k && SZ(nodes) >= 3)
            {
                string boss = nodes[0];
                for (auto node : nodes)
                {
                    if (degs[node] > degs[boss])
                        boss = node;
                }
                ans.push_back({SZ(nodes), boss});
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << SZ(ans) << '\n';
    for (auto &[sz, boss] : ans)
    {
        cout << boss << " " << sz << '\n';
    }

    return 0;
}