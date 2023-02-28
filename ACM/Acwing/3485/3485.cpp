/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-27 09:36:13
 * @FilePath: \Acwing\3485\3485.cpp
 * @LastEditTime: 2023-02-27 20:03:43
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, M = N * 32, INF = 0x3f3f3f3f;

int ver[M], root[N], son[M][2], idx;
int n, m;
int a[N];

void insert(int x, int y, int k)
// x为当前树的根节点编号，y为上一个树的根节点编号，k为第几棵树
{
    ver[x] = k;
    for (int i = 30; i >= 0; --i)
    {
        int u = a[k] >> i & 1;
        son[x][!u] = son[y][!u];
        son[x][u] = ++idx;
        x = son[x][u];
        y = son[y][u];
        ver[x] = k;
    }
}

int query(int x, int L, int v)
// x为当前树的根节点，L为不能超越的树编号左边界，v为输入函数的定值
{
    for (int i = 30; i >= 0; --i)
    {
        int u = v >> i & 1;
        if (ver[son[x][!u]] >= L)
            x = son[x][!u];
        else
            x = son[x][u];
    }
    return a[ver[x]] ^ v;
}

signed main()
{
    IOS;
    cin >> n >> m;
    // init
    root[0] = ++idx;
    ver[0] = -1;
    insert(root[0], 0, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] ^= a[i - 1];
        root[i] = ++idx;
        insert(root[i], root[i - 1], i);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        res = max(res, query(root[i], max(0, i - m), a[i]));
    }
    cout << res << '\n';
    return 0;
}