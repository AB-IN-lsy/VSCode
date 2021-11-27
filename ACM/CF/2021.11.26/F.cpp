/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-25 10:13:38
 * @FilePath: \ACM\test.cpp
 * @LastEditTime: 2021-11-26 00:52:41
 */
// Problem: F. ATM and Students
// Contest: Codeforces
// Author: NEFU AB-IN
// Edit Time:2021-11-25 22:35:15
// URL: https://codeforces.com/contest/1611/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
    LL n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    LL i = 1, j = 1, ii = -1, jj = -1, sum = 0;
    while (i <= j && j <= n + 1)
    {
        if (sum + m >= 0)
        {
            if (j - i > jj - ii)
            {
                ii = i;
                jj = j;
            }
            sum += a[j++];
        }
        else
        {
            sum -= a[i++];
        }
    }
    if (ii == -1 && jj == -1)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ii << " " << jj - 1 << '\n';
    }
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