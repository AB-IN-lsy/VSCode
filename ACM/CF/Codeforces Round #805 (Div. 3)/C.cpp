// Problem: C. Train and Queries
// Contest: Codeforces Round #805 (Div. 3)
// Author: NEFU AB-IN
// Edit Time:2022-07-12 01:34:51
// URL: https://codeforces.com/contest/1702/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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

const int INF = INT_MAX;
const int N = 1e6 + 10;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    map<int, int> x, y;
    for (int i = 0; i < n; ++i)
    {
        x[a[i]] = i; // 记录元素最末尾的位置
    }
    for (int i = n - 1; i >= 0; --i)
    {
        y[a[i]] = i; // 记录元素最开始的位置
    }

    for (int i = 0; i < k; ++i)
    {
        int l, r;
        cin >> l >> r;
        if (!x.count(l) || !y.count(r) || y[l] > x[r])
            cout << "NO\n";
        else
            cout << "YES\n";
    }

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