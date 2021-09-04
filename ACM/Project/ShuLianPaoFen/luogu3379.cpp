/*
 * @Author: NEFU AB_IN
 * @Date: 2021-09-04 22:33:01
 * @FilePath: \Vscode\ACM\Project\ShuLianPaoFen\luogu3379.cpp
 * @LastEditTime: 2021-09-04 22:55:49
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
struct Edge
{
    int v, ne;
} e[N << 2];
int h[N], cnt;
void add(int u, int v)
{
    e[cnt].v = v;
    e[cnt].ne = h[u];
    h[u] = cnt++;
}

int son[N], sizx[N], pre[N], deep[N];
int top[N];

void dfs1(int u, int fa)
{
    pre[u] = fa;
    sizx[u] = 1;
    deep[u] = deep[fa] + 1;
    int maxson = -1;
    for (int i = h[u]; ~i; i = e[i].ne)
    {
        int v = e[i].v;
        if (v != fa)
        {
            dfs1(v, u);
            sizx[u] += sizx[v];
            if (maxson < sizx[v])
            {
                maxson = sizx[v];
                son[u] = v;
            }
        }
    }
}
void dfs2(int u, int t)
{
    top[u] = t;
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (int i = h[u]; ~i; i = e[i].ne)
    {
        int v = e[i].v;
        if (v != pre[u] && v != son[u])
            dfs2(v, v);
    }
}
int lca(int x, int y){
    while(top[x] != top[y]){
        if(deep[top[x]] < deep[top[y]]) swap(x, y);
        x = pre[top[x]];
    }
    return deep[x] > deep[y] ? y : x;
}

signed main()
{
    IOS;
    memset(h, -1, sizeof h);
    int n, m, s;
    cin >> n >> m >> s;
    for(int i = 1; i < n; ++ i){
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs1(s, 0);
    dfs2(s, s);
    while(m --){
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}