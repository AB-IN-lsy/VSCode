/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-13 22:54:27
 * @FilePath: \ACM\CF\2021.10.13\b.cpp
 * @LastEditTime: 2021-10-13 23:31:55
 */
// Problem: B. Make it Divisible by 25
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// Author: NEFU AB-IN
// Edit Time:2021-10-13 22:37:38
// URL: https://codeforces.com/contest/1593/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 1e6 + 10;
int a[N];

void solve()
{
    string s;
    cin >> s;
    int ans = INF;
    for (int i = SZ(s) - 1; i >= 0; --i)
    {
        if (s[i] == '5')
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (s[j] == '2')
                {
                    ans = min(ans, SZ(s) - j - 2);
                }
                if (s[j] == '7')
                {
                    ans = min(ans, SZ(s) - j - 2);
                }
            }
        }
        if (s[i] == '0')
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (s[j] == '5')
                {
                    ans = min(ans, SZ(s) - j - 2);
                }
                if (s[j] == '0')
                {
                    ans = min(ans, SZ(s) - j - 2);
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}