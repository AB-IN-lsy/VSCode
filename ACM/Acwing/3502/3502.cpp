/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-28 23:27:38
 * @FilePath: \Acwing\3502\3502.cpp
 * @LastEditTime: 2023-02-28 23:49:01
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

const int N = 10, INF = 0x3f3f3f3f;

int g[N][N];
bool st[N][N];
map<int, bool> mp;
int n, m, k, ans;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int x, int y, int num)
{
    int len = log10(num) + 1;
    if (len == k + 1)
    {
        if (!mp[num])
        {
            ans++;
            mp[num] = true;
        }
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        int dx = dir[i][0], dy = dir[i][1];
        int x1 = x + dx, y1 = y + dy;
        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m)
        {
            int num1 = num * 10 + g[x1][y1];
            // st[x1][y1] = true;
            dfs(x1, y1, num1);
            // st[x1][y1] = false;
        }
    }
    return;
}

signed main()
{
    IOS;

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> g[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dfs(i, j, g[i][j]);

    cout << ans << '\n';
    return 0;
}