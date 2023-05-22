/*
 * @Author: NEFU AB-IN
 * @Date: 2023-05-02 16:39:28
 * @FilePath: \Acwing\3480\3480.cpp
 * @LastEditTime: 2023-05-02 17:04:19
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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

struct sa
{
    int x, y, c, w;
};

signed main()
{
    IOS;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            cin >> g[i][j];
        }
    }

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    int ans = INF;
    queue<sa> q;
    q.push({sx, sy, 0, 1});

    while (SZ(q))
    {
        auto t = q.front();
        q.pop();

        int x = t.x, y = t.y, c = t.c, w = t.w;
        if (x == ex && y == ey)
        {
            ans = min(ans, c);
            continue;
        }
        if (c > ans)
            continue;

        for (int i = 0; i < 4; ++i)
        {
            int a = x + dx[i];
            int b = y + dy[i];

            if (a < 0 || a > 5 || b < 0 || b > 5)
                continue;

            int cn = c + w * g[a][b];
            int wn = (w * g[a][b] % 4) + 1;
            q.push({a, b, cn, wn});
        }
    }

    cout << ans;

    return 0;
}