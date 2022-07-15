/*
 * @Author: NEFU AB-IN
 * @Date: 2022-06-21 15:39:07
 * @FilePath: \ACM\Acwing\3371\3371.cpp
 * @LastEditTime: 2022-06-21 16:09:10
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e3 + 10;

int st[N][N];
int vis[N][N];
int dir[5][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}};
signed main()
{
    IOS;

    int n, cnt = 0;
    cin >> n;

    auto judge = [&](int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 4; ++i)
        {
            int x1 = x + dir[i][0];
            int y1 = y + dir[i][1];

            if (x1 >= 0 && y1 >= 0 && st[x1][y1])
                cnt += 1;
        }
        if (!vis[x][y] && cnt == 3)
        {
            vis[x][y] = 1;
            return 1;
        }
        else if (vis[x][y])
        {
            vis[x][y] = 0;
            return -1;
        }
        return 0;
    };

    while (n--)
    {
        int x, y;
        cin >> x >> y;
        st[x][y] = 1;

        for (int i = 0; i < 5; ++i)
        {
            int x1 = x + dir[i][0];
            int y1 = y + dir[i][1];
            if (x1 >= 0 && y1 >= 0 && st[x1][y1])
                cnt += judge(x1, y1);
        }

        cout << cnt << '\n';
    }

    return 0;
}