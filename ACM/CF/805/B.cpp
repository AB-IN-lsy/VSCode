// Problem: B. Polycarp Writes a String from Memory
// Contest: Codeforces Round #805 (Div. 3)
// Author: NEFU AB-IN
// Edit Time:2022-07-12 01:34:50
// URL: https://codeforces.com/contest/1702/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
    string s;
    cin >> s;
    int cnt = 0, ans = 0;

    map<char, int> st;
    for (int i = 0; i < SZ(s); ++i)
    {
        if (cnt == 3 && !st[s[i]])
        {
            cnt = 0;
            ans++;
            st.clear();
        }

        if (!st[s[i]])
        {
            st[s[i]] = 1;
            cnt++;
        }
    }

    cout << ans + 1 << '\n';

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