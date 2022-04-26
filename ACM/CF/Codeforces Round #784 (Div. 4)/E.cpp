// Problem: E. 2-Letter Strings
// Contest: Codeforces Round #784 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-04-21 22:45:31
// URL: https://codeforces.com/contest/1669/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
map<char, map<char, int>> t;

void solve()
{
    int n, sum = 0;
    cin >> n;
    t.clear();
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        for (char x = 'a'; x <= 'z'; ++x)
        {
            if (x != s[1])
                sum += t[s[0]][x];
            if (x != s[0])
                sum += t[x][s[1]];
        }
        t[s[0]][s[1]] += 1;
    }
    cout << sum << '\n';
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