/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-23 23:39:55
 * @FilePath: \Acwing\1089\1089.cpp
 * @LastEditTime: 2023-02-23 23:48:23
 */
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

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

int f[N], a[N];
signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    deque<int> q;
    q.push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        while (SZ(q) && i - q.front() > m)
            q.pop_front();
        f[i] = f[q.front()] + a[i];
        while (SZ(q) && f[q.back()] >= f[i])
            q.pop_back();
        q.push_back(i);
    }

    int res = INF;
    for (int i = n - m + 1; i <= n; ++i)
        res = min(res, f[i]);

    cout << res;
    return 0;
}