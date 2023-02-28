/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-23 21:36:31
 * @FilePath: \Acwing\135\135.cpp
 * @LastEditTime: 2023-02-23 21:58:40
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

const int N = 3e5 + 10, INF = 0x3f3f3f3f;
int a[N], s[N];

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;

    deque<int> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    q.push_back(0); // 队列一定要有值，不然q.front无法取
    int res = -INF;
    for (int i = 1; i <= n; ++i)
    {
        while (SZ(q) && i - q.front() > m)
            q.pop_front();
        res = max(res, s[i] - s[q.front()]);
        while (SZ(q) && s[q.back()] >= s[i])
            q.pop_back();
        q.push_back(i);
    }

    cout << res;
    return 0;
}