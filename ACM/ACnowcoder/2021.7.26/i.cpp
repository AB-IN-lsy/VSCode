/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-26 13:20:52
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-26 13:26:56
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
const LL N = 200005;
LL n, a[N];
LL cnt[N], tree[N];

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
int main()
{
    IOS;
    cin >> n;
    for (LL i = 1; i <= n; i++)
        cin >> a[i];
    for (LL i = 1; i <= n; i++)
    {
        if (cnt[a[i] + 1])
            a[i]++;
        cnt[a[i]]++;
    }
    LL ans = 0;
    for (LL i = 1; i <= n; i++)
    {
        add(a[i], 1);
        ans += (i - sum(a[i]));
    }
    cout << ans << endl;
    return 0;
}