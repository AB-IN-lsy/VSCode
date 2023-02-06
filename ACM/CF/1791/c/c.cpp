/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-03 22:35:26
 * @FilePath: \CF\1791\c\c.cpp
 * @LastEditTime: 2023-02-03 22:46:12
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
    int ans = n;
    for (int i = 0; i < SZ(s); ++i)
    {
        if (ans == 0)
            break;
        if (s[i] == '0' && s[SZ(s) - i - 1] == '1')
            ans -= 2;
        else if (s[i] == '1' && s[SZ(s) - i - 1] == '0')
            ans -= 2;
        else
        {
            cout << ans << '\n';
            return;
        }
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
        solve();
    return 0;
}