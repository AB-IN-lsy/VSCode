/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-30 09:33:17
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-30 09:34:15
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
typedef pair<int, int> PII;

const double eps = 1e-8;
double p[1005][1005][3];
double dp[1005][1005];
int r, c;
bool equal(double a, double b)
{
    return fabs(a - b) < eps;
}

int main()
{
    while (~scanf("%d%d", &r, &c))
    {
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                scanf("%lf%lf%lf", &p[i][j][0], &p[i][j][1], &p[i][j][2]);
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int i = r; i > 0; i--)
        {
            for (int j = c; j > 0; j--)
            {
                if (i == r && j == c)
                    continue;
                if (!equal(p[i][j][0], 1.0))
                {
                    dp[i][j] = dp[i][j + 1] * p[i][j][1] + dp[i + 1][j] * p[i][j][2] + 2;
                    dp[i][j] /= (1.0 - p[i][j][0]);
                }
            }
        }
        printf("%.3f\n", dp[1][1]);
    }
    return 0;
}