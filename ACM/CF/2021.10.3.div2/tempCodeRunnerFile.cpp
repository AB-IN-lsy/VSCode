/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-03 22:34:40
 * @FilePath: \ACM\CF\2021.10.3.div2\a.cpp
 * @LastEditTime: 2021-10-03 22:59:38
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 1e6 + 10;
LL a[N];

void solve()
{
    LL n, H;
    cin >> n >> H;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<LL>());
    LL ans = 0;
    LL tmp = a[1] + a[2];
    if (H <= a[1])
    {
        cout << "1\n";
    }
    else if (H <= tmp)
    {
        cout << "2\n";
    }
    else
    {
        int tt = H / tmp;
        if (tt == 0)
        {
            cout << tt * 2 << '\n';
        }
        if (H - tt * tmp > a[1])
            cout << tt * 2 + 2 << '\n';
        else if (H - tt * tmp <= a[1])
            cout << tt * 2 + 1 << '\n';
    }
}
signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}