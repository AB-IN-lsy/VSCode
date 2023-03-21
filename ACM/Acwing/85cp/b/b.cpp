/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-02 18:39:23
 * @FilePath: \Acwing\85cp\b\b.cpp
 * @LastEditTime: 2023-02-02 19:09:55
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

string s;
int k, mx;
unordered_map<char, int> mp;

signed main()
{
    IOS;
    cin >> s >> k;
    for (char i = 'a'; i <= 'z'; ++i)
    {
        int x;
        cin >> x;
        mp[i] = x;
        mx = max(mx, x);
    }

    int ans = 0;
    for (int i = 0; i < SZ(s); ++i)
    {
        ans += (i + 1) * mp[s[i]];
    }
    // DEBUG(ans);
    for (int i = SZ(s) + 1; i < SZ(s) + 1 + k; ++i)
    {
        ans += i * mx;
    }

    cout << ans;
    return 0;
}