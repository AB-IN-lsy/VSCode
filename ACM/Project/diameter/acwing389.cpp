/*
 * @Author: NEFU AB_IN
 * @Date: 2021-09-10 17:02:55
 * @FilePath: \Vscode\ACM\Project\diameter\acwing389.cpp
 * @LastEditTime: 2021-09-10 17:38:00
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
int h[N];
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

int c;
int d[N];
void dfs(int u, int fa)
{
    for (int i = h[u]; ~i; i = e[i].ne)
    {
        int v = e[i].v;
        if (fa == v)
            continue;
        d[v] = d[u] + e[i].w;
        if (d[v] > d[c])
            c = v;
        dfs(v, u);
    }
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
    d[c] = 0;
    dfs(c, 0);
    cout << d[c] << '\n';
    return 0;
}