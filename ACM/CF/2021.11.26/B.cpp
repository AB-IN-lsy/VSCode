// Problem: B. Team Composition: Programmers and Mathematicians
// Contest: Codeforces
// Author: NEFU AB-IN
// Edit Time:2021-11-25 22:35:10
// URL: https://codeforces.com/contest/1611/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

// 四个学生
// 不能四个数学，四个编程
// 至少一个数学一个编程

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

void solve()
{
    LL n, m;
    cin >> n >> m;
    LL ans = (n + m) / 4;
    cout << min(min(ans, n), m) << '\n';
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