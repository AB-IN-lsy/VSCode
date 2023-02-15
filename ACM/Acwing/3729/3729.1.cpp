/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-14 22:01:09
 * @FilePath: \Acwing\3729\3729.1.cpp
 * @LastEditTime: 2023-02-14 22:01:15
 */
#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
const int N = 1000005, E = 524288;
int x[N], y[N], i, mp, c, t, f[N], a[N];
long long n, m, k;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (i = 1; i <= n; ++i)
            f[i] = 0;
        for (i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            ++f[max(i - a[i] + 1, 1)];
            --f[i + 1];
        }
        for (i = 1; i <= n; ++i)
            f[i] += f[i - 1];
        for (i = 1; i <= n; ++i)
            printf("%d ", f[i] ? 1 : 0);
        printf("\n");
    }
}
