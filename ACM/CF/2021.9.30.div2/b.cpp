/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-30 17:58:50
 * @FilePath: \ACM\CF\2021.9.30.div2\b.cpp
 * @LastEditTime: 2021-09-30 20:12:46
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long

void solve()
{
    LL n, m, k;
    cin >> n >> m >> k;
    LL mxx = n * (n - 1) / 2;
    if (n == 1)
    {
        if (k <= 1 || m > 0)
            cout << "NO\n";
        else
            cout << "YES\n";
        return;
    }
    k -= 2;
    if (m < n - 1 || k <= 0 || m > mxx)
        cout << "NO\n";
    else if (k == 1 && m != mxx)
        cout << "NO\n";
    else
        cout << "YES\n";
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}