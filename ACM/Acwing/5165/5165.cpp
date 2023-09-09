/*
 * @Author: NEFU AB-IN
 * @Date: 2023-09-01 20:55:01
 * @FilePath: \Acwing\5165\5165.cpp
 * @LastEditTime: 2023-09-02 02:00:37
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

const int N = 1e3 + 10, INF = 0x3f3f3f3f;

char g[N][N];

struct sa
{
    int x, y, step;
    int flag; // 是否拐过弯
    int dr;   // 方向 上下左右 1234
              // 左上 右上 左下 右下 5678
};

int dir[9][2] = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};

signed main()
{
    // freopen("Tests/input_1.txt", "r", stdin);
    IOS;
    string s;
    cin >> s;
    int len = SZ(s);
    s = " " + s;

    int R, C;
    cin >> R >> C;

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            cin >> g[i][j];
        }
    }

    int ans = 0;
    queue<sa> q;

    auto check = [&](int x, int y) { return (x <= R && x >= 1 && y >= 1 && y <= C); };

    auto bfs = [&]() {
        while (SZ(q))
        {
            sa t = q.front();
            q.pop();

            if (t.step == len)
            {
                // cout << t.x << " " << t.y << '\n';
                ans++;
                continue;
            }
            if (t.dr == 0)
            {
                for (int i = 1; i <= 8; ++i)
                {
                    int tx = t.x + dir[i][0];
                    int ty = t.y + dir[i][1];
                    if (check(tx, ty) && g[tx][ty] == s[t.step + 1])
                        q.push({tx, ty, t.step + 1, t.flag, i});
                }
            }
            else
            {
                int tx = t.x + dir[t.dr][0];
                int ty = t.y + dir[t.dr][1];

                if (!t.flag)
                {
                    int l = 1, r = 4;
                    if (t.dr > 4)
                        l = 5, r = 8;
                    for (int i = l; i <= r; ++i)
                    {
                        int xx = t.x + dir[i][0];
                        int xy = t.y + dir[i][1];
                        if (check(xx, xy) && g[xx][xy] == s[t.step + 1])
                            q.push({xx, xy, t.step + 1, i != t.dr, i});
                    }
                }
                else
                {
                    if (check(tx, ty) && g[tx][ty] == s[t.step + 1])
                        q.push({tx, ty, t.step + 1, t.flag, t.dr});
                }
            }
        }
    };

    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            if (g[i][j] == s[1])
            {
                q.push({i, j, 1, 0, 0});
                bfs();
            }
    cout << ans;
    return 0;
}
