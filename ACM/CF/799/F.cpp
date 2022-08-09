// Problem: F. 3SUM
// Contest: Codeforces Round #799 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-06-29 22:47:32
// URL: https://codeforces.com/contest/1692/problem/F
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
    int n, x;
    cin >> n;
    unordered_map<int, int> d;
    vector<int> a;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        x %= 10;
        if (++d[x] > 3)
            d[x] = 3;
        else
            a.push_back(x);
    }
    for (int i = 0; i < SZ(a); ++i)
    {
        for (int j = i + 1; j < SZ(a); ++j)
        {
            for (int k = j + 1; k < SZ(a); ++k)
            {
                if ((a[i] + a[j] + a[k]) % 10 == 3)
                {
                    puts("YES");
                    return;
                }
            }
        }
    }
    puts("NO");
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