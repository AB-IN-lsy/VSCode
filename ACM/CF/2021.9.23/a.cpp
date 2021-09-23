/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-23 20:03:59
 * @FilePath: \ACM\CF\2021.9.23\a.cpp
 * @LastEditTime: 2021-09-23 20:44:24
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
    int v, ne;
} e[N << 2];
int h[N], vis[N];
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
vector<int> vv;
int pos;
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    vis[x] = 1;

    while (q.size())
    {
        int u = q.front(), cnt1 = 0;
        q.pop();
        set<int> s;
        for (int i = h[u]; ~i; i = e[i].ne)
        {
            int v = e[i].v;
            if (vis[v])
                continue;
            vis[v] = 1;
            s.insert(v);
        }
        for (int i = pos; i < SZ(vv); ++i)
        {
            if (!SZ(s))
                break;
            if (s.find(vv[i]) != s.end())
            {
                s.erase(vv[i]);
                q.push(vv[i]);
                cnt1++;
            }
        }
        if (SZ(s))
        {
            cout << "No" << '\n';
            return;
        }
        pos += cnt1;
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
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        vv.push_back(x);
    }
    if (vv[0] != 1)
    {
        cout << "No" << '\n';
        return 0;
    }
    vv.erase(vv.begin());
    bfs(1);
    if (pos == SZ(vv))
    {
        cout << "Yes" << '\n';
    }
    return 0;
}