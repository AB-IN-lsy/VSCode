// Problem: E. Add Modulo 10
// Contest: Codeforces Round #811 (Div. 3)
// Author: NEFU AB-IN
// Edit Time:2022-08-01 22:35:13
// URL: https://codeforces.com/contest/1714/problem/E
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
const int N = 1e6 + 10;

void solve()
{
    int n;
    cin >> n;
    int flag = 0;
    int t1 = -1, t2 = -1;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x % 5 == 0)
        {
            if (x % 10 == 5)
                x += 5;
            if (t1 != -1)
            {
                if (t1 != x)
                    flag = 1;
            }
            else
                t1 = x;
        }
        else
        {
            int re = x % 10;
            int judge = 0;
            if (re % 3 && re != 7)
            {
                if ((x / 10) & 1)
                    judge = 1;
                else
                    judge = 2;
            }
            else
            {
                if ((x / 10) & 1)
                    judge = 2;
                else
                    judge = 1;
            }
            if (t2 != -1)
            {
                if (t2 != judge)
                    flag = 1;
            }
            else
                t2 = judge;
        }
    }
    if (flag)
        cout << "No\n";
    else if (t1 != -1 && t2 != -1)
        cout << "No\n";
    else
        cout << "Yes\n";
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