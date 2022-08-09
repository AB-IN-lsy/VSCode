// Problem: B. ICPC Balloons
// Contest: Codeforces Round #806 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-07-12 22:36:35
// URL: https://codeforces.com/contest/1703/problem/B
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
    string s;
    cin >> s;

    map<char, int> st;
    int ans = 0;
    for (auto i : s)
    {
        if (!st.count(i))
            ans += 2;
        else
            ans++;

        st[i] = 1;
    }
    cout << ans << '\n';
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