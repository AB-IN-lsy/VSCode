/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-10 13:29:42
 * @FilePath: \ACM\Hdu\2021.10.10\1006.cpp
 * @LastEditTime: 2021-10-10 13:29:42
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

int dp[N], pre[N];
signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        for (int i = 0; s[i]; ++i)
        {
            if (s[i] == 'n')
            {
                if (pre[i] == 0)
                {
                    dp[i] = mul(dp[i - 1], 2);
                }
                else
                {
                    dp[i] = mul(dp[i - 1], dp[pre[i]]);
                }
            }
        }
    }
    return 0;
}