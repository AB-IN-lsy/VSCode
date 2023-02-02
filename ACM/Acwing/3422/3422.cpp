/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-18 12:22:11
 * @FilePath: \Acwing\3422\3422.cpp
 * @LastEditTime: 2023-01-28 10:44:41
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

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int n;
vector<int> g[N];
int dp[N], num[N];

void dfs(int u)
{
    for (auto v : g[u])
    {
        dfs(v);
        dp[u] = max(dp[u], dp[v] + num[u]);
    }
}

signed main()
{
    IOS;
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
        num[x]++;
    }
    dfs(1);
    cout << dp[1];
    return 0;
}