/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-09 13:57:06
 * @FilePath: \GPLT\A1040\A1040.cpp
 * @LastEditTime: 2023-01-09 19:06:00
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

const int N = 1e4 + 10, INF = 0x3f3f3f3f;

signed main()
{
    IOS;
    string s;
    getline(cin, s);
    int ans = 1;
    for (int i = 0; i < SZ(s); ++i)
    {
        // odd
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < SZ(s) && s[l] == s[r])
            l--, r++;
        ans = max(ans, r - l - 1);
        // even
        l = i, r = i + 1;
        while (l >= 0 && r < SZ(s) && s[l] == s[r])
            l--, r++;
        ans = max(ans, r - l - 1);
    }
    cout << ans;
    return 0;
}