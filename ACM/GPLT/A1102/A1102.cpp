/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-13 14:45:07
 * @FilePath: \GPLT\A1102\A1102.cpp
 * @LastEditTime: 2022-09-13 15:10:32
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

// #undef N
// const int N = 1e5 + 10;

// #undef int

signed main()
{
    IOS;
    int n;
    cin >> n;

    vector<int> l(n, -1), r(n, -1), st(n);
    for (int i = 0; i < n; ++i)
    {
        char p, q;
        cin >> p >> q;
        if (p != '-')
            l[i] = p - '0', st[p - '0'] = 1;
        if (q != '-')
            r[i] = q - '0', st[q - '0'] = 1;
    }

    int root = 0;
    for (int i = 0; i < n; ++i)
        if (!st[i])
        {
            root = i;
            break;
        }

    queue<int> q;
    q.push(root);

    vector<int> c, zh;
    while (SZ(q))
    {
        auto t = q.front();
        q.pop();
        c.push_back(t);
        if (r[t] != -1)
            q.push(r[t]);
        if (l[t] != -1)
            q.push(l[t]);
    }

    for (int i = 0; i < SZ(c); ++i)
        cout << c[i] << " "[i == SZ(c) - 1];
    cout << '\n';

    function<void(int)> dfs = [&](int u) {
        if (!~u)
            return;
        dfs(r[u]);
        zh.push_back(u);
        dfs(l[u]);
    };

    dfs(root);
    for (int i = 0; i < SZ(zh); ++i)
        cout << zh[i] << " "[i == SZ(zh) - 1];
    return 0;
}