// Problem: C. Polycarp Recovers the Permutation
// Contest: Codeforces
// Author: NEFU AB-IN
// Edit Time:2021-11-25 22:35:11
// URL: https://codeforces.com/contest/1611/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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

deque<int> a, b;
void solve()
{
    a.clear();
    b.clear();
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        a.push_back(x);
    }
    if (a.front() != n and a.back() != n)
    {
        cout << -1 << '\n';
        return;
    }
    if (a.front() == n)
    {
        a.push_back(a.front());
        a.pop_front();
    }
    b.push_back(a.front());
    a.pop_front();
    while (a.size())
    {
        if (a.front() < b.back())
        {
            b.push_front(a.front());
            a.pop_front();
        }
        else if (a.back() > b.front())
        {
            b.push_back(a.back());
            a.pop_back();
        }
    }
    for (auto i : b)
    {
        cout << i << " ";
    }
    cout << '\n';
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