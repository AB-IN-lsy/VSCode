// Problem: D. Double Strings
// Contest: Codeforces Round #806 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-07-12 22:36:37
// URL: https://codeforces.com/contest/1703/problem/D
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
    int n;
    cin >> n;
    set<string> ss;
    vector<string> a;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        ss.insert(s);
        a.push_back(s);
    }

    for (int i = 0; i < n; ++i)
    {
        int flag = 0;
        for (int j = 0; j < SZ(a[i]); ++j)
        {
            string f = a[i].substr(0, j + 1);
            string l = a[i].substr(j + 1, SZ(a[i]) - j - 1);
            if (ss.find(f) != ss.end() && ss.find(l) != ss.end())
            {
                flag = 1;
                cout << 1;
                break;
            }
        }
        if (!flag)
            cout << 0;
    }
    cout << '\n';

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