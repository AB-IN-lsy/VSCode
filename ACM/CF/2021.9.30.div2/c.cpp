/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-01 15:57:43
 * @FilePath: \ACM\CF\2021.9.30.div2\c.cpp
 * @LastEditTime: 2021-10-01 16:59:08
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
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 550;
char a[N][N], sum[N][N];

int getsum(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int f(int x1, int y1, int x2, int y2)
{
    int ans = 0;
    ans += 2 * getsum(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
    ans -= getsum(x1, y1, x2, y2);
    ans += 2 * (x2 - x1 + y2 - y1);
    ans -= (a[x1][y1] == '0');
    ans -= (a[x1][y2] == '0');
    ans -= (a[x2][y1] == '0');
    ans -= (a[x2][y2] == '0');
    return ans;
}

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", a[i] + 1);
        for (int j = 1; j <= m; ++j)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (a[i][j] == '1');
        }
    }
    int ans = f(1, 1, 5, 4);

    for (int i = 1; i + 4 <= n; ++i)
    {
        for (int ii = i + 4; ii <= n; ++ii)
        {
            int j = 1;
            for (int jj = 4; jj <= m; ++jj)
            {
                int tmp;
                if ((tmp = f(i, j, ii, jj)) < ans)
                {
                    ans = tmp;
                }
                while (jj - j > 3 && (tmp = f(i, j + 1, ii, jj)) < ans)
                {
                    j++;
                    ans = tmp;
                }

                if ((tmp = f(i, jj - 3, ii, jj)) < ans)
                {
                    j = jj - 3;
                    ans = tmp;
                }
            }
        }
    }
    printf("%d\n", ans);
}

signed main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}