/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-10 12:26:22
 * @FilePath: \ACM\Hdu\2021.10.10\1011.cpp
 * @LastEditTime: 2021-10-10 13:11:55
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

const int N = 1e5 + 10;
struct Edge
{
    int v, ne;
} e[N << 2];
int h[N], a[N], ans[N];
int cnt;
void add(int u, int v)
{
    e[cnt].v = v;
    e[cnt].ne = h[u];
    h[u] = cnt++;
}
void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        h[i] = -1;
    }
    cnt = 0;
}

struct sa
{
    int u, w, fa;
    bool operator<(const sa &a) const
    {
        return w > a.w;
    }
    sa(int w, int u, int fa) : w(w), u(u), fa(fa){};
};

int bfs(int u, int fa)
{
    int ans = 0, mx = a[u];
    priority_queue<sa> q;
    q.push(sa(a[u], u, fa));
    ans++;
    while (q.size())
    {
        sa m = q.top();
        q.pop();
        for (int i = h[m.u]; ~i; i = e[i].ne)
        {
            int v = e[i].v;
            if (m.fa == v)
                continue;
            if (a[v] > mx)
            {
                mx = max(mx, a[v]);
                ans++;
            }
            q.push(sa(a[v], v, m.u));
        }
    }
    return ans;
}

signed main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        init(n);
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; ++i)
        {
            printf("%d\n", bfs(i, 0));
        }
    }
    return 0;
}