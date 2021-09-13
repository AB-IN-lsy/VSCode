/*
 * @Author: NEFU AB_IN
 * @Date: 2021-09-13 20:22:37
 * @FilePath: \Vscode\ACM\NiuKe\2021.9.13\b.cpp
 * @LastEditTime: 2021-09-13 21:25:47
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

const int N = 1E6 + 10;
struct Edge
{
    int v, w, ne;
} e[N << 2];
int cnt, h[N];
void add(int u, int v, int w)
{
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].ne = h[u];
    h[u] = cnt++;
}
struct sa
{
    int w, to;
    bool operator<(const sa &a) const
    {
        return w > a.w;
    }
    sa(int w, int to) : w(w), to(to){};
};

priority_queue<sa> q;

int vis[N], d[N];
int n;
void dij(int s)
{
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    q.push(sa(0, s));
    while (q.size())
    {
        sa t = q.top();
        q.pop();
        int u = t.to;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = h[u]; ~i; i = e[i].ne)
        {
            int v = e[i].v;
            if (d[u] + e[i].w < d[v])
            {
                d[v] = d[u] + e[i].w;
                q.push(sa(e[i].w, v));
            }
        }
    }
}

signed main()
{
    memset(h, -1, sizeof h);
    for (int i = 1; i <= 2021; ++i)
    {
        for (int j = i + 1; j <= 2021; ++j)
        {
            if (abs(i - j) <= 21)
            {
                int w = i / __gcd(i, j) * j;
                add(i, j, w);
            }
        }
    }
    dij(1);
    cout << d[2021];
    return 0;
}
