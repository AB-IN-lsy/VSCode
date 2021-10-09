/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-03 23:55:53
 * @FilePath: \ACM\CF\2021.10.3.div2\c.cpp
 * @LastEditTime: 2021-10-07 19:36:13
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
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
int a[N];
struct Edge
{
    int v, ne;
} e[N << 2];
int h[N];
int cnt, ans, sum;
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
    ans = 0;
    sum = 0;
}

int dfs(int u, int fa)
{
    int tmp = a[u];
    for (int i = h[u]; ~i; i = e[i].ne)
    {
        int v = e[i].v;
        if (fa == v)
            continue;
        tmp ^= dfs(v, u);
    }
    if (tmp == sum)
    {
        ans++;
        return 0;
    }
    return tmp;
}

void solve()
{
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        sum ^= a[i];
    }
    int u, v;
    for (int i = 1; i < n; ++i)
    {

        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    if (!sum)
    {
        printf("YES\n");
        return;
    }
    dfs(1, 0);
    if (k >= 3 && ans >= 3)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

signed main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}