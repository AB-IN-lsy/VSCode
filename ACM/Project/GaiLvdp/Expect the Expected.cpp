/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-30 09:29:40
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-30 23:34:23
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
double f[105][105];

int dcmp(double x)
{
    if (fabs(x) < eps)
        return 0;
    else if (x > 0)
        return 1;
    else
        return -1;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        int n, a, b;
        scanf("%d/%d%d", &a, &b, &n); 
        double p = (double)a / b;

        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        f[0][1] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; dcmp((double)j / i - p) <= 0; j++)
            {
                f[i][j] = f[i - 1][j] * (1 - p);
                if (j)
                    f[i][j] += f[i - 1][j - 1] * p;
            }

        double Q = 0;
        for (int i = 0; dcmp((double)i / n - p) <= 0; i++)
            Q += f[n][i];

        printf("Case #%d: %d\n", cas, (int)(1 / Q));
    }
    return 0;
}