// Problem: E. Binary Deque
// Contest: Codeforces Round #799 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-06-29 22:47:31
// URL: https://codeforces.com/contest/1692/problem/E
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
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum < s)
    {
        cout << "-1\n";
        return;
    }
    int cnt = 0, mx = 0;
    for (int i = 0, j = 0; i < n; ++i)
    {
        cnt += (a[i] == 1);
        while (j < i && cnt > s)
        {
            cnt -= (a[j++] == 1);
            if (cnt == s)
                mx = max(mx, i - j + 1);
        }
        if (cnt == s)
            mx = max(mx, i - j + 1);
    }
    cout << n - mx << '\n';
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