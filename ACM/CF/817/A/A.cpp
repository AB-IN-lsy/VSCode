/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-02 18:05:11
 * @FilePath: \817\A\A.cpp
 * @LastEditTime: 2022-09-02 18:13:14
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    auto judge = [&](int n, string s) {
        if (n != 5)
            return false;
        string ss = "Timur";
        sort(ss.begin(), ss.end());
        sort(s.begin(), s.end());

        return ss == s;
    };

    if (judge(n, s))
        cout << "YES\n";
    else
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