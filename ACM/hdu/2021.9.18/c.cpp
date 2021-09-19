/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-18 14:32:00
 * @FilePath: \Vscode\ACM\Hdu\2021.9.18\c.cpp
 * @LastEditTime: 2021-09-18 15:53:11
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((LL)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<LL, LL> PII;

const LL N = 5e3 + 10;
LL a[N], b[N], pos[N];

bool cmp(LL e, LL f)
{
    return a[e] < a[f];
}

signed main()
{
    LL t;
    scanf("%lld", &t);
    while (t--)
    {
        LL n;
        scanf("%lld", &n);
        for (LL i = 1; i <= n; ++i)
        {
            scanf("%lld", &a[i]);
        }
        for (LL i = 1; i <= n; ++i)
        {
            scanf("%lld", &b[i]);
        }
        for (LL i = 1; i <= n; ++i)
        {
            pos[i] = i;
        }
        sort(b + 1, b + 1 + n, greater<LL>()); // 从大到小
        sort(pos + 1, pos + 1 + n, cmp);       // 从小到大

        LL ans1 = 0, ans2 = 0;
        for (LL i = 1; i <= n; ++i)
        {
            LL ans1 = 0, ans2 = 0;
            //max
            LL s1 = b[1] + a[i], p = 2;
            for (LL j = 1; j <= n; ++j)
            {
                if (pos[j] == i)
                    continue;
                while (a[pos[j]] + b[p] > s1 && p <= n)
                    p++;
                if (p <= n)
                    ans1++;
                p++;
                if (p > n)
                    break;
            }
            ans1 = n - ans1;

            //min
            s1 = b[n] + a[i], p = n - 1;
            for (LL j = n; j >= 1; --j)
            {
                if (pos[j] == i)
                    continue;
                while (a[pos[j]] + b[p] <= s1 && p >= 1)
                    p--;
                if (p >= 1)
                    ans2++;
                p--;
                if (p < 1)
                    break;
            }
            printf("%lld %lld\n", ans1, ans2 + 1);
        }
    }
    return 0;
}