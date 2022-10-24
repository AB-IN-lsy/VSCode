/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-13 20:50:59
 * @FilePath: \GPLT\A1115\A1115.cpp
 * @LastEditTime: 2022-09-13 21:18:02
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

#undef N
const int N = 1e5 + 10;

// #undef int

signed main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> l(N), r(N), v(N);
    // BST 结点编号从1开始
    int root = 0, idx = 0;

    function<void(int &, int)> insert = [&](int &u, int w) {
        if (!u)
        {
            u = ++idx;
            v[u] = w;
            return;
        }
        if (v[u] >= w)
            insert(l[u], w);
        else
            insert(r[u], w);
    };

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        insert(root, x);
    }

    int mx = 0;
    vector<int> ans(N);
    function<void(int, int)> dfs = [&](int u, int dep) {
        if (!u)
            return;
        mx = max(mx, dep);
        ans[dep]++;
        dfs(l[u], dep + 1);
        dfs(r[u], dep + 1);
    };

    dfs(root, 0);

    printf("%d + %d = %d", ans[mx], ans[mx - 1], ans[mx - 1] + ans[mx]);
    return 0;
}