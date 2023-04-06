/*
 * @Author: NEFU AB-IN
 * @Date: 2023-04-02 18:49:27
 * @FilePath: \Acwing\ACC2\c\c.cpp
 * @LastEditTime: 2023-04-06 22:13:53
 */
// #pragma GCC optimize(1)
// #pragma GCC optimize(2) // 先开优化
// #pragma GCC optimize(3, "Ofast", "inline")
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

const int N = 1e3 + 10, INF = 0x3f3f3f3f;

int n, m, k;
struct sa
{
    int x, y;
} s[N];

int sx, sy, ex, ey;
int dist[N][N];
char g[N][N];
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int bfs()
{
    queue<sa> q;
    q.push({sx, sy});
    memset(dist, 0x3f, sizeof dist);
    dist[sx][sy] = 0;
    while (SZ(q))
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                int x = t.x + j * dir[i][0];
                int y = t.y + j * dir[i][1];
                if (x < 1 || x > n || y < 1 || y > m || g[x][y] == '#')
                    break;
                if (dist[x][y] < dist[t.x][t.y] + 1)
                    // 在一个方向上枚举时，如果到达点的最短步数(dist[x][y])小于等于当前点(dist[t.x][t.y])的位置，就立马
                    // break 掉
                    // 因为到达点的距离就不用目前点更新，所以目前点就可以直接break
                    break;
                if (dist[x][y] > dist[t.x][t.y] + 1)
                {
                    dist[x][y] = dist[t.x][t.y] + 1;
                    if (x == ex && y == ey) // 直接判断，防止多循环一次
                        return dist[x][y];
                    q.push({x, y});
                }
            }
        }
    }
    return -1;
}

signed main()
{
    // IOS;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> (g[i] + 1);
    }
    cin >> sx >> sy >> ex >> ey;
    if (sx == ex && sy == ey)
        cout << "0\n";
    else
        cout << bfs() << '\n';
    return 0;
}