/*
 * @Author: NEFU AB_IN
 * @Date: 2021-09-04 18:43:00
 * @FilePath: \Vscode\ACM\Project\ShuLianPaoFen\hdu3966.cpp
 * @LastEditTime: 2021-09-04 20:10:16
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
int h[N];
int cnt;
void add(int u, int v)
{
    e[cnt].v = v;
    e[cnt].ne = h[u];
    h[u] = cnt++;
}
void init()
{
    memset(h, -1, sizeof(h));
    cnt = 0;
}

int w[N];
int pre[N], sizx[N], son[N], deep[N];
int dfn[N], top[N], a[N];
int cnx; // dfs2 pool

void dfs1(int u, int fa)
{
    pre[u] = fa;
    deep[u] = deep[fa] + 1;
    sizx[u] = 1;
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

void dfs2(int u, int t) // 因dfs1已经标记了重儿子，按重儿子递归，然后标记每个儿子的头
{
    top[u] = t;
    dfn[u] = ++cnx;
    a[cnx] = w[u];
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (int i = h[u]; ~i; i = e[i].ne)
    {
        int v = e[i].v;
        if (v != pre[u] && v != son[u])
        {
            dfs2(v, v); //标记轻儿子，轻儿子的头就是它本身
        }
    }
}
// 重写线段树
struct xds
{
    int l, r, p, lazy;
} tr[N << 2];

void pushdown(int k)
{
    if (tr[k].lazy)
    {
        tr[k << 1].p += tr[k].lazy;
        tr[k << 1 | 1].p += tr[k].lazy;
        tr[k << 1].lazy += tr[k].lazy;
        tr[k << 1 | 1].lazy += tr[k].lazy;
        tr[k].lazy = 0;
    }
}

void build(int k, int l, int r)
{
    tr[k].l = l;
    tr[k].r = r;
    tr[k].lazy = 0;
    if (l == r)
    {
        tr[k].p = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
}

void modify(int k, int ql, int qr, int w)
{
    if (tr[k].l >= ql && tr[k].r <= qr)
    {
        tr[k].p += w;
        tr[k].lazy += w;
        return;
    }
    pushdown(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (ql <= mid)
        modify(k << 1, ql, qr, w);
    if (qr > mid)
        modify(k << 1 | 1, ql, qr, w);
}

int query(int k, int pos) //单点查询
{
    if (tr[k].l == tr[k].r)
    {
        return tr[k].p;
    }
    pushdown(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (mid >= pos)
        query(k << 1, pos);
    else
        query(k << 1 | 1, pos);
}

void mtre(int x, int y, int z)
{
    while (top[x] != top[y]) // 一直递归到头不同
    {
        if (deep[top[x]] < deep[top[y]]) // 挑选头重的（即深度大），优先进行操作
        {
            swap(x, y);
        }
        modify(1, dfn[top[x]], dfn[x], z); // 利用线段树，操作这一个链，（是对dfs序进行操作，而不是节点标号）
        x = pre[top[x]];                   // x变成x的头
    }
    if (deep[x] > deep[y])
    { // 头相同了，说明在同一条链上，这时挑个头轻的
        swap(x, y);
    }
    modify(1, dfn[x], dfn[y], z);
}

signed main()
{
    IOS int n, m, q;
    while (cin >> n >> m >> q)
    {
        memset(son, 0, sizeof son);
        cnx = 0;
        init();
        for (int i = 1; i <= n; ++i)
        {
            cin >> w[i];
        }
        for (int i = 1; i <= m; ++i)
        {
            int u, v;
            cin >> u >> v;
            add(u, v);
            add(v, u);
        }
        dfs1(1, 0);
        dfs2(1, 1);
        build(1, 1, n);
        while(q --){
            char c;
            cin >> c;
            if(c == 'I'){
                int u, v, w;
                cin >> u >> v >> w;
                mtre(u, v, w);
            }
            if(c == 'D'){
                int u, v, w;
                cin >> u >> v >> w;
                mtre(u, v, -w);
            }
            if(c == 'Q'){
                int u;
                cin >> u;
                cout << query(1, dfn[u]) << '\n';
            }
        }
    }
    return 0;
}