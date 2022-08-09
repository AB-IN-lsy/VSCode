// Problem: B. Triple
// Contest: Codeforces Round #784 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-04-21 22:45:28
// URL: https://codeforces.com/contest/1669/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

map<int, int> vis;

void solve()
{
    int n;
    vis.clear();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        vis[x] += 1;
    }
    for (auto [k, v] : vis)
    {
        if (v >= 3)
        {
            cout << k << '\n';
            return;
        }
    }
    cout << "-1\n";
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