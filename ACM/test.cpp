// Problem: E. Robot on the Board 1
// Contest: Codeforces Round #753 (Div. 3)
// Author: NEFU AB-IN
// Edit Time:2021-11-02 22:35:35
// URL: https://codeforces.com/contest/1607/problem/E
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
    int n, m;
    cin >> n >> m;
    string s;
    int r = 0, d = 0, u = 0, l = 0, rmax = 0, dmax = 0, umax = 0, lmax = 0;
    for (auto i : s)
    {
        if (i == 'L')
            r--, l++;
        if (i == 'R')
            r++, l--;
        if (i == 'D')
            d++, u--;
        if (i == 'U')
            d--, u++;
        rmax = max(rmax, r);
        dmax = max(dmax, d);
        umax = max(umax, u);
        lmax = max(lmax, l);
    }
    cout << lmax << " " << dmax << '\n';
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