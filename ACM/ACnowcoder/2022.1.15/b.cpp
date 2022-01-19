/*
 * @Author: NEFU AB-IN
 * @Date: 2022-01-15 13:12:28
 * @FilePath: \ACM\ACnowcoder\2022.1.15\b.cpp
 * @LastEditTime: 2022-01-15 13:14:13
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

signed main()
{
    IOS;
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        m[s] += 1;
    }
    int ans = 0;
    for (auto &[k, b] : m)
    {
        ans++;
    }
    cout << ans << '\n';
    return 0;
}