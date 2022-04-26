// Problem: C. Odd/Even Increments
// Contest: Codeforces Round #784 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-04-21 22:45:29
// URL: https://codeforces.com/contest/1669/problem/C
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
    int n;
    cin >> n;
    vector<int> odd;
    vector<int> even;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (i & 1)
            odd.push_back(a[i]);
        else
            even.push_back(a[i]);
    }
    for (int i = 0; i < SZ(odd) - 1; ++i)
    {
        if ((odd[i] & 1) != (odd[i + 1] & 1))
        {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < SZ(even) - 1; ++i)
    {
        if ((even[i] & 1) != (even[i + 1] & 1))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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