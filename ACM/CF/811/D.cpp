// Problem: D. Color with Occurrences
// Contest: Codeforces Round #811 (Div. 3)
// Author: NEFU AB-IN
// Edit Time:2022-08-01 22:35:12
// URL: https://codeforces.com/contest/1714/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
const int N = 110;

// 做好超时的准备

void solve()
{

    string s;
    cin >> s;
    int n;
    cin >> n;

    vector<string> v[26];
    vector<PII> ans;
    vector<int> st(SZ(s));
    map<string, int> mp;

    for (int i = 0; i < n; ++i)
    {
        string ss;
        cin >> ss;
        v[ss[0] - 'a'].push_back(ss);
        mp[ss] = i + 1;
    }

    for (int i = 0; i < 26; ++i)
        sort(v[i].begin(), v[i].end());

    int i = 0;
    while (i < SZ(s))
    {
        int u = s[i] - 'a';
        if (SZ(v[u]))
        {
            string anss;
            int flag = 0;
            for (auto ss : v[u])
            {
                if (s.substr(i, SZ(ss)) == ss)
                {
                    anss = ss;
                    flag = 1;
                }
            }
            if (flag)
            {
                st[i] = 1;
                ans.push_back({mp[anss], i + 1});
                i += SZ(anss);
            }
            else
            {
                i--;
                if (i < 0 || st[i])
                {
                    cout << "-1\n";
                    return;
                }
            }
        }
        else
        {
            i--;
            if (i < 0 || st[i])
            {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << SZ(ans) << '\n';
    for (auto [i, j] : ans)
    {
        cout << i << " " << j << '\n';
    }

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