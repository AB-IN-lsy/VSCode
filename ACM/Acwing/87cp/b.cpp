/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-29 21:45:13
 * @FilePath: \Acwing\87cp\b.cpp
 * @LastEditTime: 2023-01-29 21:56:57
 */
#pragma GCC optimize(1)
#pragma GCC optimize(2) // 先开优化
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e3 + 10, INF = 0x3f3f3f3f;

int n, m;
int a[N];

bool check(int id)
{
    int cnt = m;
    vector<int> b;
    for (int i = 1; i <= id; ++i)
        b.push_back(a[i]);
    sort(ALL(b), greater<int>());
    for (int i = 0; i < SZ(b); i += 2)
    {
        cnt -= b[i];
        if (cnt < 0)
            return false;
    }
    return true;
}

signed main()
{
    IOS;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l;
    return 0;
}