// Problem: A. Round Down the Price
// Contest: Codeforces Round #805 (Div. 3)
// Author: NEFU AB-IN
// Edit Time:2022-07-12 01:34:49
// URL: https://codeforces.com/contest/1702/problem/A
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
    int n;
    cin >> n;
    cout << n - (int)pow(10, (int)log10(n)) << '\n';

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