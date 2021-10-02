/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-02 16:41:19
 * @FilePath: \ACM\LuoGu\1387\main.cpp
 * @LastEditTime: 2021-10-02 16:57:57
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
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, m;
const int N = 150;
int a[N][N], sum[N][N];

signed main()
{
    IOS;
    cin >> n >> m;
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
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int d = 0; i + d <= n && j + d <= m; ++d)
            {
                int ii = i + d;
                int jj = j + d;
                int tmp = sum[ii][jj] - sum[ii][j - 1] - sum[i - 1][jj] + sum[i - 1][j - 1];
                if (tmp == (ii - i + 1) * (jj - j + 1))
                {
                    ans = max(ans, ii - i + 1);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}