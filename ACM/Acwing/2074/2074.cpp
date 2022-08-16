/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-13 15:39:09
 * @FilePath: \Acwing\2074\2074.cpp
 * @LastEditTime: 2022-08-13 16:01:19
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

void solve(int T)
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (i > 1 && a[i - 1] - a[i] == 1)
        {
            b[i] = b[i - 1] = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
        b[i] += b[i - 1];

    int ans = 0;
    for (int i = 1; i + k - 1 <= n; ++i)
    {
        if (a[i] - a[i + k - 1] == k - 1 && b[i + k - 1] - b[i - 1] == k && a[i + k - 1] == 1)
            ans += 1;
    }
    printf("Case #%lld: %lld\n", T, ans);
    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        solve(i);
    }
    return 0;
}