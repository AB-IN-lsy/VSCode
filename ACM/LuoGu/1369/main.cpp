/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-02 16:02:50
 * @FilePath: \ACM\LuoGu\1369\main.cpp
 * @LastEditTime: 2021-10-02 16:17:21
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

const int N = 350;
int a[N][N], sum[N][N];

signed main()
{
    IOS;
    int n, mx = 0, my = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        mx = max(mx, x);
        my = max(my, y);
        a[x][y] = 1;
    }
    for (int i = 1; i <= mx; ++i)
    {
        for (int j = 1; j <= my; ++j)
        {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= mx; ++i)
    {
        for (int j = 1; j <= my; ++j)
        {
            for (int ii = i + 1; ii <= mx; ++ii)
            {
                for (int jj = j + 1; jj <= my; ++jj)
                {
                    int tmp = sum[ii][jj] - sum[ii][j - 1] - sum[i - 1][jj] + sum[i - 1][j - 1];
                    tmp -= (sum[ii - 1][jj - 1] - sum[ii - 1][j] - sum[i][jj - 1] + sum[i][j]);
                    ans = max(ans, tmp);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}