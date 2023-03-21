/*
 * @Author: NEFU AB-IN
 * @Date: 2023-03-01 09:22:35
 * @FilePath: \Acwing\165\165.cpp
 * @LastEditTime: 2023-03-01 10:14:16
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

const int N = 20, INF = 0x3f3f3f3f;
int c[N], sum[N];
int n, w;
int ans = INF;
void dfs(int u, int k)
{
    if (k >= ans)
        return;
    if (u == n + 1)
    {
        ans = k;
        return;
    }
    for (int i = 0; i < k; ++i)
    {
        if (c[u] + sum[i] <= w)
        {
            sum[i] += c[u];
            dfs(u + 1, k);
            sum[i] -= c[u];
        }
    }
    sum[k] = c[u];
    dfs(u + 1, k + 1);
    sum[k] = 0;
}

signed main()
{
    IOS;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }
    sort(c + 1, c + 1 + n, greater<int>());
    dfs(1, 1);
    cout << ans << '\n';
    return 0;
}