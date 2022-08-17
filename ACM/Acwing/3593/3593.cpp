/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-17 10:03:36
 * @FilePath: \Acwing\3593\3593.cpp
 * @LastEditTime: 2022-08-17 10:13:12
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

signed main()
{
    IOS;
    string s;
    while (cin >> s)
    {
        int ans = SZ(s);
        if (s[ans - 1] == '.')
            ans--;
        cout << ans << ' ';
    }
    return 0;
}