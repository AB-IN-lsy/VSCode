/*
 * @Author: NEFU AB-IN
 * @Date: 2022-12-13 21:03:36
 * @FilePath: \Acwing\1603\1603.cpp
 * @LastEditTime: 2022-12-13 21:05:47
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());
    int s1 = 0, s2 = 0;

    for (int i = 0; i < n / 2; ++i)
        s1 += a[i];
    for (int i = n / 2; i < n; ++i)
        s2 += a[i];

    cout << (n & 1) << ' ' << s2 - s1 << '\n';
    return 0;
}