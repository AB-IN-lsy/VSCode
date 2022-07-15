// Problem: G. 2^Sort
// Contest: Codeforces Round #799 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-06-29 22:47:33
// URL: https://codeforces.com/contest/1692/problem/G
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

const int INF = INT_MAX;
const int N = 1e6 + 10;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (i > 1 && a[i - 1] >= 2 * a[i])
        {
            // DEBUG(i - k + 1)
            // DEBUG(b[i - k + 1])
            b[max(1LL, i - k)]++;
            b[i]--;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        b[i] += b[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!b[i] && i + k <= n)
        {
            ans++;
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