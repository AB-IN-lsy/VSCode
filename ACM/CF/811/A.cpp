// Problem: A. Everyone Loves to Sleep
// Contest: Codeforces Round #811 (Div. 3)
// Author: NEFU AB-IN
// Edit Time:2022-08-01 22:35:09
// URL: https://codeforces.com/contest/1714/problem/A
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
    int n, H, M;
    cin >> n >> H >> M;
    int ans1 = H * 60 + M, ans = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        int h, m;
        cin >> h >> m;
        if (h < H || (h == H && m < M))
            h += 24;
        int ans2 = h * 60 + m;
        ans = min(ans, ans2 - ans1);
    }
    cout << ans / 60 << " " << ans % 60 << '\n';
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