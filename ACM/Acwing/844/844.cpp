/*
 * @Author: NEFU AB-IN
 * @Date: 2023-04-06 23:19:14
 * @FilePath: \Acwing\844\844.cpp
 * @LastEditTime: 2023-04-06 23:24:55
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 110;

struct sa
{
    int x, y;
};

int n, m;
int dist[N][N], g[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void print()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}

int bfs()
{
    queue<sa> q;
    q.push({1, 1});
    memset(dist, 0x3f, sizeof dist);
    dist[1][1] = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int x = t.x + dx[i];
            int y = t.y + dy[i];
            if (x < 1 || x > n || y < 1 || y > m || g[x][y] == 1)
                continue;
            if (dist[x][y] > dist[t.x][t.y] + 1)
            {
                dist[x][y] = dist[t.x][t.y] + 1;
                // print();
                if (x == n && y == m)
                {
                    return dist[x][y];
                }
                q.push({x, y});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> g[i][j];
        }
    }
    cout << bfs();
    return 0;
}