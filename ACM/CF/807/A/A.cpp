/*
 * @Author: NEFU AB-IN
 * @Date: 2022-07-15 21:36:52
 * @FilePath: \807\A\A.cpp
 * @LastEditTime: 2022-07-15 21:39:19
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
    int n, k;
    cin >> n >> k;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 1, j = n + 1; i <= n; ++i, ++j)
    {
        if (a[j] - a[i] < k)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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