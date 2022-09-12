/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-12 21:57:40
 * @FilePath: \GPLT\A1099\A1099.cpp
 * @LastEditTime: 2022-09-12 22:07:13
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

    vector<int> l(N), r(N), w(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> l[i] >> r[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i];
    }

    sort(w.begin(), w.end());

    int k = 0;
    vector<int> ans(N);
    function<void(int)> dfs = [&](int u) {
        if (!~u)
            return;
        dfs(l[u]);
        ans[u] = w[k++];
        dfs(r[u]);
    };

    dfs(0);

    queue<int> q;
    q.push(0);

    while (SZ(q))
    {
        auto t = q.front();
        q.pop();
        cout << ans[t] << " ";
        if (~l[t])
            q.push(l[t]);
        if (~r[t])
            q.push(r[t]);
    }
    return 0;
}