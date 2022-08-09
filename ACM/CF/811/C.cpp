// Problem: C. Minimum Varied Number
// Contest: Codeforces Round #811 (Div. 3)
// Author: NEFU AB-IN
// Edit Time:2022-08-01 22:35:11
// URL: https://codeforces.com/contest/1714/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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

vector<int> v = {0,      1,      2,      3,      4,       5,       6,       7,        8,        9,        19,    29,
                 39,     49,     59,     69,     79,      89,      189,     289,      389,      489,      589,   689,
                 789,    1789,   2789,   3789,   4789,    5789,    6789,    16789,    26789,    36789,    46789, 56789,
                 156789, 256789, 356789, 456789, 1456789, 2456789, 3456789, 13456789, 23456789, 123456789};

void solve()
{
    int n;
    cin >> n;

    cout << v[n] << '\n';
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