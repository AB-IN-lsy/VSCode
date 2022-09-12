/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-12 20:20:02
 * @FilePath: \GPLT\A1064\A1064.cpp
 * @LastEditTime: 2022-09-12 20:40:35
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

    vector<int> w(n), tr(N);

    for (int i = 0; i < n; ++i)
        cin >> w[i];
    sort(w.begin(), w.end());

    int id = 0;
    function<void(int)> dfs = [&](int u) {
        if (u * 2 <= n)
            dfs(u * 2);
        tr[u] = w[id++];
        if (u * 2 + 1 <= n)
            dfs(u * 2 + 1);
    };

    dfs(1);

    cout << tr[1];
    for (int i = 2; i <= n; ++i)
    {
        cout << " " << tr[i];
    }

    return 0;
}