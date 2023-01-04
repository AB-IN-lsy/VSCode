/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-03 11:29:30
 * @FilePath: \Acwing\4644\4644.cpp
 * @LastEditTime: 2023-01-03 11:31:40
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
    vector<int> a(N), b(N);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += a[i] * (b[n] - b[i]);
    }
    cout << ans;
    return 0;
}