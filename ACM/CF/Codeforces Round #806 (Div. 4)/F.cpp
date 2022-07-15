// Problem: F. Yet Another Problem About Pairs Satisfying an Inequality
// Contest: Codeforces Round #806 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-07-12 22:36:39
// URL: https://codeforces.com/contest/1703/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
    int n;
    cin >> n;
    vector<int> a(n + 1), st(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] < i)
        {
            st[i] = 1; // 记录是否有资格进行配对
            b[1]++;
            b[a[i]]--;
        }
        // cout << st1[i] << " ";
    }

    for (int i = 1; i <= n; ++i)
    {
        b[i] += b[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (st[i])
        {
            ans += b[i];
        }
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