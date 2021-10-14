/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-10 13:29:42
 * @FilePath: \ACM\Hdu\2021.10.10\1006.cpp
 * @LastEditTime: 2021-10-13 18:30:14
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
LL qm(LL a, LL b, LL c)
{
    LL ret = 1 % c;
    while (b)
    {
        if (b & 1)
            ret = ret * a % c;
        a = a * a % c;
        b = b >> 1;
    }
    return ret;
}
const int N = 1e5 + 10;
const LL mod = 998244353;
LL mul(LL x, LL y)
{
    return 1LL * x * y % mod;
}
LL dec(LL x, LL y)
{
    return x >= y ? x - y : x + mod - y;
}
LL add(LL x, LL y)
{
    return x + y >= mod ? x + y - mod : x + y;
}
LL pmod(LL x)
{
    return (x + mod) % mod;
}

LL dp[10], a[N];
signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        string ss = "0nunhehheh";
        cin >> s;
        memset(dp, 0, sizeof dp);
        memset(a, 0, sizeof a);
        for (int i = SZ(s) - 1; i >= 0; --i)
        {
            a[i] = a[i + 1] + (s[i] == 'a');
        }
        dp[0] = 1;
        LL ans = 0;
        for (int i = 0; s[i]; ++i)
        {
            LL t = dp[9];
            for (int j = 9; j >= 1; --j)
            {
                if (s[i] == ss[j])
                {
                    dp[j] = add(dp[j], dp[j - 1]);
                }
            }
            ans = add(ans, mul(dec(dp[9], t), dec(qm(2, a[i], mod), 1)));
        }
        cout << ans << '\n';
    }
    return 0;
}