/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-12 19:01:41
 * @FilePath: \GPLT\A1021\A1021.cpp
 * @LastEditTime: 2022-09-12 19:35:46
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

#undef N
const int N = 1e4 + 10;

#undef int
int fa[N];
vector<int> g[N];

int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int dfs(int fa, int u)
{
    int d = 0;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        d = max(d, dfs(u, v) + 1);
    }
    return d;
}

signed main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
    }

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        if (find(u) != find(v))
        {
            fa[find(u)] = find(v);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (fa[i] == i)
            cnt++;
    }
    if (cnt > 1)
    {
        printf("Error: %d components", cnt);
        return 0;
    }

    vector<int> ans;
    int mx = 0;
    for (int i = 1; i <= n; ++i)
    {
        int d = dfs(-1, i);
        if (d > mx)
        {
            mx = d;
            ans.clear();
            ans.push_back(i);
        }
        else if (d == mx)
            ans.push_back(i);
    }

    printf("%d", ans[0]);
    for (int i = 1; i < SZ(ans); ++i)
    {
        printf("\n%d", ans[i]);
    }

    return 0;
}