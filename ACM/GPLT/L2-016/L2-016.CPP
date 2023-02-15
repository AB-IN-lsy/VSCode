/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-21 15:25:25
 * @FilePath: \ACM\GPLT\L2-016.CPP
 * @LastEditTime: 2022-04-21 18:49:57
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 1e6 + 10;
vector<int> g[N];
int n, k, flag, st[N];

unordered_map<int, char> vis;

void dfs(int u, int cnt)
{
    if (flag || cnt >= 5)
        return;
    st[u] = 1;
    for (auto v : g[u])
    {
        if (st[v])
        {
            flag = 1;
            return;
        }
        dfs(v, cnt + 1);
    }
}

signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int id, fa, ma;
        char op;
        cin >> id >> op >> fa >> ma;
        vis[id] = op;
        if (fa != -1)
            g[id].push_back(fa);
        if (ma != -1)
            g[id].push_back(ma);
    }

    cin >> k;
    for (int i = 1; i <= k; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (vis[u] == vis[v])
        {
            cout << "Never Mind\n";
        }
        else
        {
            flag = 0;
            memset(st, 0, sizeof st);
            dfs(u, 0);
            dfs(v, 0);
            if (!flag)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}