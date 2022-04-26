// Problem: D. Colorful Stamp
// Contest: Codeforces Round #784 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-04-21 22:45:30
// URL: https://codeforces.com/contest/1669/problem/D
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

int check(string s)
{
    int b = 0, r = 0;
    for (int i = 0; i < SZ(s); ++i)
    {
        if (s[i] == 'B')
            b++;
        else
            r++;
    }
    if (b && r)
        return 1;
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = 0;
    for (int i = 0; i < SZ(s); ++i)
    {
        if (s[i] == 'W')
            continue;
        else
        {
            l = i;
            while (s[i] != 'W' && i < SZ(s))
                i++;
            i--;
            r = i;
            if (!check(s.substr(l, r - l + 1)))
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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