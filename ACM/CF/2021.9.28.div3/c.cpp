/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-29 00:20:19
 * @FilePath: \ACM\CF\2021.9.28.div3\c.cpp
 * @LastEditTime: 2021-09-29 00:46:32
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
typedef pair<int, int> pII;
const int INF = 0x3f3f3f3f;

const int N = 100;
char a[N][N];
bool f[N][N];

void solve()
{
    memset(f, 0, sizeof f);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '*')
            {
                for (int d = k; d <= n; ++d)
                {
                    int flag = 0;
                    if (i - d < 1 || j - d < 1 || j + d > m)
                    {
                        break;
                    }
                    for (int kk = 1; kk <= d; ++kk)
                    {
                        if (a[i - kk][j - kk] != '*')
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag)
                        continue;
                    for (int kk = 1; kk <= d; ++kk)
                    {
                        if (a[i - kk][j + kk] != '*')
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag)
                    {
                        f[i][j] = 1;
                        for (int kk = 1; kk <= d; ++kk)
                        {
                            f[i - kk][j - kk] = 1;
                        }
                        for (int kk = 1; kk <= d; ++kk)
                        {
                            f[i - kk][j + kk] = 1;
                        }
                    }
                }
            }
        }
    }
    int flag = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == '*' && f[i][j] == 0)
            {
                flag = 1;
                cout << "NO\n";
                break;
            }
        }
        if (flag)
            break;
    }
    if (!flag)
        cout << "YES\n";
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}