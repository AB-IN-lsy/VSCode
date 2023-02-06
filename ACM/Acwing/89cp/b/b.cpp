/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-04 18:58:52
 * @FilePath: \Acwing\89cp\b\b.cpp
 * @LastEditTime: 2023-02-04 19:16:48
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

const int N = 110, INF = 0x3f3f3f3f;

int b[N][N], a[N][N];

signed main()
{
    IOS;
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> b[i][j];
            a[i][j] = -1;
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (b[i][j] == 0)
            {
                for (int x = 1; x <= m; ++x)
                {
                    a[x][j] = 0;
                }
                for (int y = 1; y <= n; ++y)
                {
                    a[i][y] = 0;
                }
            }
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (b[i][j] == 1)
            {
                int cnt = 0;
                for (int x = 1; x <= m; ++x)
                {
                    if (a[x][j] == -1 || a[x][j] == 1)
                        cnt++;
                    if (a[x][j] == -1)
                        a[x][j] = 1;
                }
                for (int y = 1; y <= n; ++y)
                {
                    if (a[i][y] == -1 || a[i][y] == 1)
                        cnt++;
                    if (a[i][y] == -1)
                        a[i][y] = 1;
                }
                if (cnt == 0)
                {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}