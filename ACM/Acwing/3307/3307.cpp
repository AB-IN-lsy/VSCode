/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-16 16:14:28
 * @FilePath: \Acwing\3307\3307.cpp
 * @LastEditTime: 2022-08-16 16:25:14
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
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(N);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        int ans = 0, mx = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (i == n && a[i] > mx)
                ans++;
            if ((i < n && a[i] > a[i + 1]) && a[i] > mx)
            {
                ans++;
            }
            mx = max(mx, a[i]);
        }
        printf("Case #%lld: %lld\n", _, ans);
    }
    return 0;
}