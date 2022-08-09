/*
 * @Author: NEFU AB-IN
 * @Date: 2021-11-02 23:17:07
 * @FilePath: \ACM\test1.cpp
 * @LastEditTime: 2022-04-21 23:56:05
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 2e5 + 10;
int a[N], s[50];
void solve()
{
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    memset(s, 0, sizeof s);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= 30; ++j)
        {
            s[j] += (a[i] >> j) & 1;
        }
    }
    for (int i = 30; i >= 0; --i)
    {
        if (k >= n - s[i])
        {
            ans = ans | (1 << i);
            k -= (n - s[i]);
        }
    }
    cout << ans << '\n';
    return;
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}