/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-05 12:25:32
 * @FilePath: \Acwing\3675\3675.cpp
 * @LastEditTime: 2022-09-05 20:15:30
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

const int N = 110;

char g[N][N];
int st[N][N][4], dist[N][N][4];

bool solve()
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);

    int m, n;
    scanf("%d%d", &m, &n); // m行n列
    for (int i = 1; i <= m; ++i)
    {
        scanf("%s", g[i] + 1);
    }
    int k, sx, sy, ex, ey;
    scanf("%d%d%d%d%d", &k, &sy, &sx, &ey, &ex);

    vector<PII> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    struct sa
    {
        int x, y, dir;
    };

    deque<sa> q;

    auto check = [&](int x, int y) { return (x >= 1 && x <= m && y >= 1 && y <= n && g[x][y] != '*'); };

    for (int i = 0; i < 4; ++i)
    {
        int x = sx + dir[i].first;
        int y = sy + dir[i].second;
        if (check(x, y))
        {
            q.push_front({x, y, i});
            dist[x][y][i] = 0;
        }
    }

    while (SZ(q))
    {
        sa t = q.front();
        q.pop_front();
        int x = t.x, y = t.y, d = t.dir;

        if (st[x][y][d])
            continue;
        st[x][y][d] = 1;

        if (dist[x][y][d] > k)
            continue;
        if (x == ex && y == ey)
        {
            return true;
        }
        for (int i = 0; i < 4; ++i)
        {
            int xx = t.x + dir[i].first;
            int yy = t.y + dir[i].second;

            if (check(xx, yy))
            {
                int w = i != d;
                if (dist[xx][yy][i] > dist[x][y][d] + w)
                {
                    dist[xx][yy][i] = dist[x][y][d] + w;
                    if (w)
                        q.push_back({xx, yy, i});
                    else
                        q.push_front({xx, yy, i});
                }
            }
        }
    }
    return false;
}

signed main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        if (solve())
            cout << "yes\n";
        else
            cout << "no\n";
    return 0;
}