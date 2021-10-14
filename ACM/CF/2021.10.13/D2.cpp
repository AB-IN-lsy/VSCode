// Problem: D2. Half of Same
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// Author: NEFU AB-IN
// Edit Time:2021-10-13 22:37:48
// URL: https://codeforces.com/contest/1593/problem/D2
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
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (auto [x, y] : mp)
    {
        if (y >= n / 2)
        {
            cout << "-1\n";
            return;
        }
    }
    set<int> cha1;
    set<int> cha2;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            cha1.insert(abs(a[i] - a[j]));
        }
    }
    for (auto i : cha1)
    {
        for (auto j : cha1)
        {
            cha2.insert(__gcd(i, j));
        }
    }
    int ans = 0;
    for (auto ii : cha2)
    {
        if (!ii)
            continue;
        for (int i = 1; i <= n; i++)
        {
            int tmp = 0;
            for (int j = 1; j <= n; j++)
            {
                int now = abs(a[i] - a[j]);
                if (now % ii == 0)
                    tmp++;
            }
            if (tmp >= n / 2)
                ans = max(ans, ii);
        }
    }
    cout << ans << '\n';
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