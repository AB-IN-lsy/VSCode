/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-28 18:53:44
 * @FilePath: \Acwing\88cp\b.cpp
 * @LastEditTime: 2023-01-28 19:39:06
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

const int N = 1e4 + 10, INF = 0x3f3f3f3f;

vector<int> g[N];
int st[N];
int n, m, cnt;

void dfs(int u)
{
    cnt++;
    st[u] = 1;
    for (auto v : g[u])
    {
        if (!st[v])
            dfs(v);
    }
}

signed main()
{
    IOS;
    cin >> n >> m;
    string x, y;
    cin >> x >> y;

    auto f = [&](int x, int y) { return y * m + x; };

    for (int j = 0; j < n; ++j)
    {
        if (x[j] == '>')
            for (int i1 = 0, j1 = j; i1 < m - 1; ++i1)
                g[f(i1, j1)].push_back(f(i1 + 1, j1));
        else
            for (int i1 = m - 1, j1 = j; i1 > 0; --i1)
                g[f(i1, j1)].push_back(f(i1 - 1, j1));
    }
    for (int i = 0; i < m; ++i)
    {
        if (y[i] == 'v')
            for (int i1 = i, j1 = 0; j1 < n - 1; ++j1)
                g[f(i1, j1)].push_back(f(i1, j1 + 1));
        else
            for (int i1 = i, j1 = n - 1; j1 > 0; --j1)
                g[f(i1, j1)].push_back(f(i1, j1 - 1));
    }

    for (int i = 0; i < n * m; ++i)
    {
        cnt = 0;
        memset(st, 0, sizeof st);
        dfs(i);
        if (cnt != n * m)
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}