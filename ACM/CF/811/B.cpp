// Problem: B. Remove Prefix
// Contest: Codeforces Round #811 (Div. 3)
// Author: NEFU AB-IN
// Edit Time:2022-08-01 22:35:10
// URL: https://codeforces.com/contest/1714/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), st(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        st[a[i]] += 1;
    }
    int ans = INF;
    for (int i = 0; i < n; ++i)
    {
        if (st[a[i]] == 1)
        {
            ans = min(ans, i);
        }
        else
        {
            ans = INF;
        }
        st[a[i]]--;
    }
    cout << ans << '\n';
    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}