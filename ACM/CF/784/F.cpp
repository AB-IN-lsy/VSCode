// Problem: F. Eating Candies
// Contest: Codeforces Round #784 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-04-21 22:45:32
// URL: https://codeforces.com/contest/1669/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 2e5 + 10;
int a[N];
void solve()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int l = 0, r = n + 1, ls = 0, rs = 0;
    while (l < r)
    {
        if (ls == rs)
        {
            ans = l + (n + 1) - r;
            l++;
            r--;
            ls += a[l];
            rs += a[r];
            continue;
        }
        if (ls < rs)
        {
            l++;
            ls += a[l];
            continue;
        }
        r--;
        rs += a[r];
    }
    cout << ans << '\n';
    return;
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