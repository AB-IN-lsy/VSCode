/*
 * @Author: NEFU AB-IN
 * @Date: 2022-07-15 21:36:52
 * @FilePath: \807\B\B.cpp
 * @LastEditTime: 2022-07-16 00:28:58
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int ans = 0;

    int r = 1;
    while (r < n && a[r] == 0)
    {
        r++;
    }

    for (int i = r; i < n; ++i)
    {
        if (a[i] == 0)
            ans++;
    }
    ans += (accumulate(a.begin(), a.end(), (int)0) - a[n]);
    cout << ans << '\n';

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