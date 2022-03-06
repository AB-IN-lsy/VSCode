/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-05 19:51:04
 * @FilePath: \ACM\Acwing\41\c.cpp
 * @LastEditTime: 2022-03-05 21:28:03
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 2e5 + 100;
vector<int> g[N];
vector<int> res(0);

int cnt[N], vis[N];

int dfs(int u)
{
    res.push_back(u);
    for (auto v : g[u])
    {
        int s = dfs(v);
        cnt[u] += s;
    }
    return cnt[u];
}

signed main()
{
    IOS;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n - 1; ++i)
    {
        int x;
        cin >> x;
        g[x].push_back(i + 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        cnt[i] = 1;
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
    {
        vis[res[i]] = i;
    }
    for (int i = 1; i <= q; ++i)
    {
        int u, k;
        cin >> u >> k;
        if (k > cnt[u])
        {
            cout << "-1\n";
            continue;
        }
        cout << res[vis[u] + k - 1] << '\n';
    }
    return 0;
}