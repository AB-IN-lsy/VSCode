/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-11 11:48:28
 * @FilePath: \Acwing\3540\3540.cpp
 * @LastEditTime: 2022-08-13 10:14:54
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

signed main()
{
    IOS;
    int n;
    cin >> n;

    struct sa
    {
        int l, r, val;
    };

    vector<sa> tr(N);

    // 1是根节点的链表结点
    int root, idx = 1;
    cin >> root;
    tr[idx++].val = root;

    function<void(int, int)> insert = [&](int u, int x) {
        if (!tr[u].val)
        {
            tr[u].val = x;
            return;
        }
        // 相当于创建左右儿子空结点
        if (!tr[u].l)
            tr[u].l = idx++;
        if (!tr[u].r)
            tr[u].r = idx++;
        if (x < tr[u].val)
            insert(tr[u].l, x);
        if (x > tr[u].val)
            insert(tr[u].r, x);
    };

    function<void(int, int)> dfs = [&](int u, int p) {
        if (p == 1)
            cout << tr[u].val << " ";
        if (tr[tr[u].l].val)
            dfs(tr[u].l, p);
        if (p == 2)
            cout << tr[u].val << " ";
        if (tr[tr[u].r].val)
            dfs(tr[u].r, p);
        if (p == 3)
            cout << tr[u].val << " ";
    };

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        insert(1, x);
    }
    for (int i = 1; i <= 3; ++i)
    {
        dfs(1, i);
        cout << '\n';
    }

    return 0;
}