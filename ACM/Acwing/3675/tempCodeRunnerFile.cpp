/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-05 12:25:32
 * @FilePath: \Acwing\3675\3675.cpp
 * @LastEditTime: 2022-09-05 13:03:33
 */
#include <bits/stdc++.h>
using namespace std;
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

char g[110][110];

void solve()
{
    int m, n;
    scanf("%d%d", &m, &n); // m行n列
    for (int i = 1; i <= m; ++i)
    {
        getchar();
        for (int j = 1; j <= n; ++j)
        {
            scanf("%1c", &g[i][j]);
        }
    }
    int k, sx, sy, ex, ey;
    scanf("%d%d%d%d%d", &k, &sy, &sx, &ey, &ex);

    vector<PII> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    struct sa
    {
        int x, y, dir, cnt;
    };

    queue<sa> q;
    vector<vector<int>> st(110, vector<int>(110));

    for (int i = 0; i < 4; ++i)
    {
        int x = sx + dir[i].first;
        int y = sy + dir[i].second;
        if (x >= 1 && x <= m && y >= 1 && y <= n && g[x][y] != '*' && !st[x][y])
        {
            st[x][y] = 1;
            q.push({x, y, i, 0});
        }
    }

    while (SZ(q))
    {
        sa t = q.front();
        q.pop();
        int x = t.x, y = t.y, d = t.dir;
        if (x == ex && y == ey)
        {
            if (t.cnt <= k)
            {
                cout << "yes\n";
            }
            else
                cout << "no\n";
            return;
        }
        for (int i = 0; i < 4; ++i)
        {
            int xx = t.x + dir[i].first;
            int yy = t.y + dir[i].second;
            int cnt = t.cnt + (i != d);
            if (xx >= 1 && xx <= m && yy >= 1 && yy <= n && g[xx][yy] != '*' && !st[xx][yy])
            {
                q.push({xx, yy, i, cnt});
                st[xx][yy] = 1;
            }
        }
    }
    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}