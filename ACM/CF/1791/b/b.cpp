/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-03 22:35:26
 * @FilePath: \CF\1791\b\b.cpp
 * @LastEditTime: 2023-02-03 22:40:58
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int xs = 0, ys = 0;
    for (auto x : s)
    {
        if (x == 'U')
            ys++;
        if (x == 'D')
            ys--;
        if (x == 'L')
            xs--;
        if (x == 'R')
            xs++;
        if (ys == 1 && xs == 1)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}