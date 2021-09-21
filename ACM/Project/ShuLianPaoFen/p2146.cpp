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
#define ls i << 1
#define rs i << 1 | 1
typedef pair<int, int> PII;

const int N = 20;
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

namespace TreeChain
{
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

    void dfs2(int u, int t)
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
                dfs2(v, v);
            }
        }
    }
}
using namespace TreeChain;

namespace xds_add
{
    LL a[N << 2], tr[N << 2], add_tag[N << 2], k;
    int n, x, y;

    inline void pushup(int i)
    {
        tr[i] = tr[ls] + tr[rs];
    }

    void build(int i, int l, int r)
    {
        add_tag[i] = -1;
        if (l == r)
        {
            tr[i] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(i);
    }

    inline void ADD(int i, int l, int r, LL k)
    {
        add_tag[i] = k;
        tr[i] = (r - l + 1) * k;
    }

    inline void pushdown(int i, int l, int r, int mid)
    {
        if ((add_tag[i]) == -1)
            return;
        ADD(ls, l, mid, add_tag[i]);
        ADD(rs, mid + 1, r, add_tag[i]);
        add_tag[i] = -1;
    }

    inline void update_ADD(int i, int l, int r, int x, int y, LL k)
    {
        if (l > y || r < x)
            return;
        if (l >= x && r <= y)
            return ADD(i, l, r, k);
        int mid = (l + r) >> 1;
        pushdown(i, l, r, mid);
        update_ADD(ls, l, mid, x, y, k);
        update_ADD(rs, mid + 1, r, x, y, k);
        pushup(i);
    }

    LL query(int i, int l, int r, int x, int y)
    {
        LL res = 0;
        if (l > y || r < x)
            return 0;
        if (l >= x && r <= y)
            return tr[i];
        int mid = (l + r) >> 1;
        pushdown(i, l, r, mid);
        if (x <= mid)
            res = res + query(ls, l, mid, x, y);
        if (y > mid)
            res = res + query(rs, mid + 1, r, x, y);
        return res;
    }
}
using namespace xds_add;

int install(int x)
{
    int ans = deep[x];
    while (top[x] != 1)
    {
        ans -= query(1, 1, n, dfn[top[x]], dfn[x]);
        update_ADD(1, 1, n, dfn[top[x]], dfn[x], 1);
        x = pre[top[x]];
    }
    ans -= query(1, 1, n, 1, dfn[x]);
    update_ADD(1, 1, n, 1, dfn[x], 1);
    return ans;
}

int uninstall(int x)
{
    int ans = query(1, 1, n, dfn[x], dfn[x] + sizx[x] - 1);
    update_ADD(1, 1, n, dfn[x], dfn[x] + sizx[x] - 1, 0);
    return ans;
}

signed main()
{
    init();
    IOS;
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        int x;
        cin >> x;
        add(x + 1, i);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        string s;
        int x;
        cin >> s >> x;
        x++;
        if (s == "install")
            cout << install(x) << '\n';
        else
            cout << uninstall(x) << '\n';
    }
    return 0;
}