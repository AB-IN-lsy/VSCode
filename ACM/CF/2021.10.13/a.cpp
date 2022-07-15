// Problem: A. Elections
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// Author: NEFU AB-IN
// Edit Time:2021-10-13 22:37:34
// URL: https://codeforces.com/contest/1593/problem/A
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

void solve()
{
    LL a, b, c;
    cin >> a >> b >> c;
    LL mx = max(max(a, b), c);
    int cnt = 0;
    if (a == mx)
        cnt++;
    if (b == mx)
        cnt++;
    if (c == mx)
        cnt++;
    if (cnt == 3)
    {
        cout << "1 1 1\n";
        return;
    }
    if (cnt == 2)
    {
        if (a == mx)
        {
            cout << "1 ";
        }
        else
        {
            cout << mx - a + 1 << ' ';
        }
        if (b == mx)
        {
            cout << "1 ";
        }
        else
        {
            cout << mx - b + 1 << ' ';
        }
        if (c == mx)
        {
            cout << "1\n";
        }
        else
        {
            cout << mx - c + 1 << '\n';
        }
    }
    else
    {
        if (a == mx)
        {
            cout << "0 ";
        }
        else
        {
            cout << mx - a + 1 << ' ';
        }
        if (b == mx)
        {
            cout << "0 ";
        }
        else
        {
            cout << mx - b + 1 << ' ';
        }
        if (c == mx)
        {
            cout << "0\n";
        }
        else
        {
            cout << mx - c + 1 << '\n';
        }
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