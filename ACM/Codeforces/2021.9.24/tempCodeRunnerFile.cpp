/*
    * @Author: NEFU AB-IN
    * @Date: 2021-09-24 20:21:23
 * @FilePath: \ACM\CF\2021.9.24\a.cpp
 * @LastEditTime: 2021-09-24 21:20:09
    */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((LL)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<LL, LL> PII;
const LL N = 2010;
LL a[N];

multiset<LL> b;
signed main()
{
    IOS;
    LL n, m;
    cin >> n >> m;
    for (LL i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    LL max = 0;
    for (LL i = 1; i <= n; ++i)
    {
        LL x;
        cin >> x;
        b.insert(x);
    }
    LL t = *(b.rbegin()) + m;
    sort(a + 1, a + 1 + n, greater<LL>());
    LL minx = 0x3f3f3f3f;
    for (LL i = 1; i <= n; ++i)
    {
        LL tmp = t - a[i] >= 0 ? t - a[i] : (t - a[i] + m);
        multiset<LL> s;
        for (LL i = 1; i <= n; ++i)
        {
            s.insert((a[i] + tmp) % m);
        }
        if (s == b)
        {
            minx = min(minx, tmp);
        }
    }
    cout << minx << '\n';
    return 0;
}