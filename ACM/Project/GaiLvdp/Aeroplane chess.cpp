/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-30 09:40:27
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-30 23:34:28
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

const int N = 1e5 + 10;
double dp[N];
int pre[N];

int main()
{
    IOS;
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        if (n == 0 && m == 0)
            break;
        memset(pre, -1, sizeof(pre));
        memset(dp, 0, sizeof(dp));
        int x, y;
        while (m--)
        {
            scanf("%d%d", &x, &y);
            pre[x] = y;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (pre[i] == -1)
            {
                for (int j = 1; j <= 6; j++)
                {
                    dp[i] += (dp[i + j] + 1) / 6.0;
                }
            }
            else
                dp[i] = dp[pre[i]];
        }
        printf("%.4f\n", dp[0]);
    }
    return 0;
}