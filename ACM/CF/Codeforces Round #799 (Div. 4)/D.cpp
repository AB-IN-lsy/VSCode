// Problem: D. The Clock
// Contest: Codeforces Round #799 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-06-15 23:46:50
// URL: https://codeforces.com/contest/1692/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
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
    int h, m, d;
    scanf("%d:%d %d", &h, &m, &d);

    auto ff = [&](int ans) {
        int h = ans / 60;
        int m = ans % 60;
        string sh = to_string(h);

        if (h % 10 == m / 10 && h / 10 == m % 10)
            return 1;
        return 0;
    };

    set<int> s;
    int cnt = 0;
    int ans = h * 60 + m;
    while (s.find(ans) == s.end())
    {
        s.insert(ans);
        if (ff(ans))
            cnt += 1;

        ans += d;
        ans %= 1440;
    }
    cout << cnt << '\n';
    return;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}