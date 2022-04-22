/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-20 21:16:16
 * @FilePath: \ACM\GPLT\L2-010.CPP
 * @LastEditTime: 2022-04-20 21:38:40
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

const int N = 120;
int p[N];
unordered_map<int, unordered_map<int, int>> vis;

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int n, m, k;
signed main()
{
    IOS;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, op;
        cin >> u >> v >> op;
        if (op == 1)
        {
            p[find(u)] = find(v);
        }
        else
        {
            vis[u][v] = vis[v][u] = 1;
        }
    }
    for (int i = 1; i <= k; ++i)
    {
        int u, v;
        cin >> u >> v;
        int f1 = find(u) == find(v);
        int f2 = vis[u][v] && vis[v][u];
        if (f1 && !f2)
        {
            cout << "No problem\n";
        }
        else if (f1 && f2)
        {
            cout << "OK but...\n";
        }
        else if (!f1 && !f2)
        {
            cout << "OK\n";
        }
        else
        {
            cout << "No way\n";
        }
    }
    return 0;
}