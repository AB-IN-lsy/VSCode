/*
 * @Author: NEFU AB_IN
 * @Date: 2021-09-10 17:38:09
 * @FilePath: \Vscode\ACM\Project\diameter\acwing389_.cpp
 * @LastEditTime: 2021-09-10 20:34:32
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
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
struct Edge
{
    int v, ne, w;
} e[N << 2];
int h[N], d1[N], d2[N], d;
int cnt;
void add(int u, int v, int w)
{
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].ne = h[u];
    h[u] = cnt++;
}
void init()
{
    memset(h, -1, sizeof(h));
    cnt = 0;
}
void dfs(int u, int fa)
{
    for (int i = h[u]; ~i; i = e[i].ne)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v, u);
        int t = d1[v] + e[i].w;
        if (t > d1[u])
        {
            d2[u] = d1[u];
            d1[u] = t;
        }
        else if (t > d2[u])
        {
            d2[u] = t;
        }
    }
    d = max(d, d1[u] + d2[u]);
}

signed main()
{
    IOS;
    init();
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, 0);
    cout << d << '\n';
    return 0;
}