/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-27 21:04:28
 * @FilePath: \ACM\Acwing\44\c.cpp
 * @LastEditTime: 2022-03-27 21:04:29
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100010;

int n, m;
int cnt[N];

int power(int a, int b)
{
    LL res = 1;
    while (b--)
    {
        res *= a;
        if (res >= N)
            res = 0;
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);

    LL res = 0;
    while (n--)
    {
        int x;
        scanf("%d", &x);
        LL y = 1, z = 1;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
            {
                int s = 0;
                while (x % i == 0)
                    x /= i, s++;
                s %= m;
                if (s)
                {
                    y *= power(i, s);
                    z *= power(i, m - s);
                }
            }

        if (x > 1)
            y *= x, z *= power(x, m - 1);
        if (z >= N)
            z = 0;

        res += cnt[z];
        cnt[y]++;
    }

    printf("%lld\n", res);
    return 0;
}