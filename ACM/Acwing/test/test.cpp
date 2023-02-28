/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-30 11:32:05
 * @FilePath: \Acwing\test\test.cpp
 * @LastEditTime: 2023-02-28 15:22:17
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

namespace Trie01Plus
{
int ver[M], root[N], son[M][2], idx;
int n, m;
int a[N];

void init()
{
    root[0] = ++idx;
    ver[0] = -1;
    insert(root[0], 0, 0);
}

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
            x = son[x][!u]; // res += 1 << i;
        else
            x = son[x][u];
    }
    return a[ver[x]] ^ v;
}
} // namespace Trie01Plus

signed main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    int k = upper_bound(ALL(s), 0) - s.begin();

    cout << k << '\n';
    return 0;
}