/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-02 18:16:21
 * @FilePath: \817\B\B.cpp
 * @LastEditTime: 2022-09-02 18:26:58
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
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < SZ(s1); ++i)
    {
        if (s1[i] == 'R' && s2[i] == 'R')
            cnt1++;
        if ((s1[i] == 'G' || s1[i] == 'B') && (s2[i] == 'G' || s2[i] == 'B'))
            cnt2++;
    }
    if (cnt1 + cnt2 == n)
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