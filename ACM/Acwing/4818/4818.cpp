/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-02 17:19:57
 * @FilePath: \Acwing\4818\4818.cpp
 * @LastEditTime: 2023-01-02 19:41:04
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

// #undef N
// const int N = 1e5 + 10;

// #undef int

signed main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    sort(c.begin(), c.end());

    int res = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int tmp = c[i] * (n - i);
        if (tmp > res)
        {
            res = c[i] * (n - i);
            ans = c[i];
        }
    }
    cout << res << " " << ans << '\n';
    return 0;
}