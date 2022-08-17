/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-17 16:25:17
 * @FilePath: \Acwing\2070\2070.cpp
 * @LastEditTime: 2022-08-17 16:27:32
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
    for (int _ = 1; _ <= T; _++)
    {
        int n;
        cin >> n;
        vector<int> a(N);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 2; i < n; ++i)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
                ans++;
        }
        printf("Case #%lld: %lld\n", _, ans);
    }
    return 0;
}