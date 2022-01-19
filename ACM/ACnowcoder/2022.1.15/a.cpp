/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-29 18:19:55
 * @FilePath: \ACM\ACnowcoder\2022.1.15\a.cpp
 * @LastEditTime: 2022-01-15 13:09:52
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define lowbit(x) ((x) & -(x))
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 1e6 + 10;
LL tree[N], n, t[N], a[N];
void add(LL x, LL d)
{
    while (x <= n)
    {
        tree[x] += d;
        x += lowbit(x);
    }
}
LL sum(LL x)
{
    LL sum = 0;
    while (x > 0)
    {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

void solve()
{
    memset(tree, 0, sizeof tree);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        t[i] = a[i];
    }
    sort(t + 1, t + 1 + n);
    int m = unique(t + 1, t + 1 + n) - t - 1;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = lower_bound(t + 1, t + 1 + m, a[i]) - t;
    }
    for (int i = 1; i <= n; ++i)
    {
        add(a[i], 1);
        cout << sum(a[i] - 1) << " ";
    }
}

signed main()
{
    IOS;
    solve();
    return 0;
}
