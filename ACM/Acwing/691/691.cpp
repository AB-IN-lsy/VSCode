/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-04 15:03:57
 * @FilePath: \Acwing\691\691.cpp
 * @LastEditTime: 2022-08-04 16:15:07
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

void solve(int T)
{

    int n;
    cin >> n;

    vector<vector<int>> g(n + 10, vector<int>(n + 10)), f(n + 10, vector<int>(n + 10, -1));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> g[i][j];
        }
    }

    int d = 0, r = n * n;

    function<int(int, int)> dp = [&](int x, int y) {
        if (f[x][y] != -1)
            return f[x][y];

        f[x][y] = 1; // 初始化走一步

        vector<PII> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for (int i = 0; i < 4; ++i)
        {
            int xx = x + dir[i].first;
            int yy = y + dir[i].second;

            if (xx >= 1 && x <= n && yy >= 1 && yy <= n && g[xx][yy] == g[x][y] + 1)
            {
                f[x][y] = max(f[x][y], dp(xx, yy) + 1);
            }
        }

        return f[x][y];
    };

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int step = dp(i, j);
            if (step > d || (step == d && g[i][j] < r))
            {
                d = step;
                r = g[i][j];
            }
        }
    }

    printf("Case #%lld: %lld %lld\n", T, r, d);
    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        solve(i);
    }
    return 0;
}