/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-21 10:16:41
 * @FilePath: \ACM\GPLT\L2-013.CPP
 * @LastEditTime: 2022-04-21 10:29:52
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

const int N = 510;
vector<int> g[N];
int n, m, k, st[N];

void dfs(int u, int fa)
{
    for (auto v : g[u])
    {
        if (fa == v || st[v])
            continue;
        st[v] = 1;
        dfs(v, u);
    }
}

signed main()
{
    IOS;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> k;
    vector<int> vis;
    for (int i = 1; i <= k; ++i)
    {
        int x, cnt1 = 0, cnt2 = 0;
        cin >> x;

        memset(st, 0, sizeof st);
        for (auto u : vis)
            st[u] = 1;
        for (int i = 0; i < n; ++i)
        {
            if (!st[i])
            {
                dfs(i, -1);
                cnt1 += 1;
            }
        }

        vis.push_back(x);

        memset(st, 0, sizeof st);
        for (auto u : vis)
            st[u] = 1;
        for (int i = 0; i < n; ++i)
        {
            if (!st[i])
            {
                dfs(i, -1);
                cnt2 += 1;
            }
        }
        if (cnt2 > cnt1)
            printf("Red Alert: City %lld is lost!\n", x);
        else
            printf("City %lld is lost.\n", x);
    }
    if (n == k)
        printf("Game Over.");
    return 0;
}