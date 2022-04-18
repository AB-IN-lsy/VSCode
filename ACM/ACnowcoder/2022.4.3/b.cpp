/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-03 15:12:00
 * @FilePath: \ACM\ACnowcoder\2022.4.3\b.cpp
 * @LastEditTime: 2022-04-03 15:59:53
 */
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

const int N = 1e6 + 10;
int fact[N], infact[N];

int qp(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

signed main()
{
    int t;
    scanf("%llu", &t);
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
        infact[i] = infact[i - 1] * qp(i, MOD - 2, MOD) % MOD;
    }
    while (t--)
    {
        int n, m, k, q;
        scanf("%llu%llu%llu%llu", &n, &m, &k, &q);
        q %= MOD;
        if (k > n)
        {
            printf("0\n");
            continue;
        }

        int fm = qp(fact[n + m] * fact[n - k] % MOD, MOD - 2, MOD);
        int ans = fact[n] * fact[n + m - k] * fm % MOD;
        printf("%llu\n", qp(ans, q, MOD));
    }
    return 0;
}