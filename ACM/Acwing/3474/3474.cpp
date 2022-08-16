/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-16 15:47:06
 * @FilePath: \Acwing\3474\3474.cpp
 * @LastEditTime: 2022-08-16 16:05:17
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
    int n;
    cin >> n;
    vector<PII> a(N);
    int A;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        if (!a[i].second)
            A = a[i].first;
    }
    sort(a.begin(), a.end());
    vector<int> l, r;
    for (auto [pos, v] : a)
    {
        if (v == 0 || (pos < A && v < 0) || (pos > A && v > 0))
            continue;
        if (pos < A)
            l.push_back(pos);
        else
            r.push_back(pos);
    }
    //左右蚂蚁相等, 最终A仍会静止
    if (SZ(l) == SZ(r))
        cout << "Cannot fall!";
    //左边更多时, 左边的后r.size个蚂蚁被右边抵消
    else if (SZ(l) > SZ(r))
        cout << 100 - l[SZ(l) - SZ(r) - 1];
    //右边更多时, 右边前l.size个蚂蚁被左边抵消
    else
        cout << r[SZ(l)];
    return 0;
}