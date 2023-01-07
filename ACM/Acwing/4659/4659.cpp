/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-07 09:34:39
 * @FilePath: \Acwing\4659\4659.cpp
 * @LastEditTime: 2023-01-07 09:40:16
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

#undef N
const int N = 1e5 + 10;

// #undef int

int n, m;
PII a[N];

signed main()
{
    IOS;
    cin >> n >> m;

    priority_queue<PII> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        q.push({a[i].first, i});
    }

    int res = 0;
    while (m--)
    {
        auto t = q.top();
        auto A = t.first, idx = t.second;
        q.pop();
        res += t.first;
        q.push({A - a[idx].second, idx});
    }

    cout << res << '\n';

    return 0;
}