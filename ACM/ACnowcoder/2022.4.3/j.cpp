/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-03 15:30:22
 * @FilePath: \ACM\ACnowcoder\2022.4.3\j.cpp
 * @LastEditTime: 2022-04-03 15:34:51
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
using namespace std;
char b[1000100];
int a, mod;
int euler(int n)
{
    int i, j, res = n, temp = n;
    for (i = 2; i * i <= temp; i++)
    {
        if (temp % i == 0)
        {
            res = res / i * (i - 1);
            while (temp % i == 0)
                temp /= i;
        }
    }
    if (temp > 1)
        res = res / temp * (temp - 1);
    return res;
}
int quickpow(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = (res * a) % mod;
        }
        n >>= 1;
        a = (a * a) % mod;
    }
    return res % mod;
}
signed main()
{
    int t;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld %s %lld", &a, b, &mod);
        if (a == 0 && b == "0")
        {
            puts("1");
            continue;
        }
        int len = strlen(b);
        int t1 = euler(mod);
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
            ans = (ans * 10 + b[i] - '0') % t1;
        }
        ans += t1;
        printf("%lld\n", quickpow(a, ans));
    }
    return 0;
}