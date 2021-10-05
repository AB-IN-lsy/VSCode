/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-03 22:34:47
 * @FilePath: \ACM\CF\2021.10.3.div2\b.cpp
 * @LastEditTime: 2021-10-03 23:38:24
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
int a[N], b[N];

void solve()
{
    int n, x, flag = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] < a[i - 1])
            flag = 1;
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    if (!flag)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i - 1 < x && n - i < x && a[i] != b[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
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