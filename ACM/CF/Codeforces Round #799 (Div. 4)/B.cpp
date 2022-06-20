// Problem: B. All Distinct
// Contest: Codeforces Round #799 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-06-15 23:46:48
// URL: https://codeforces.com/contest/1692/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;

void solve()
{
    int n;
    cin >> n;

    set<int> s;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    int cnt = SZ(s);

    if ((n - cnt) & 1)
        cout << cnt - 1 << '\n';
    else
        cout << cnt << '\n';
    return;
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