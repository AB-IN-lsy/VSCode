/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-03 23:55:53
 * @FilePath: \ACM\CF\2021.10.3.div2\c.cpp
 * @LastEditTime: 2021-10-04 00:24:19
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N];
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

bool dfs(int x)
{
    for (int i = h[x]; ~i; i = e[i].ne)
    {
        int v = e[i].v;
    }
}
void solve()
{
    init();
    int n, k, sum;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum ^= a[i];
    }
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    if (!sum)
    {
        cout << "YES\n";
    }
    else if (k >= 3 && dfs(1))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}