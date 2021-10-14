/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-13 23:56:44
 * @FilePath: \ACM\CF\2021.10.13\d.cpp
 * @LastEditTime: 2021-10-13 23:58:12
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
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 400010;
int a[N], b[N];

void solve()
{
    int n, cnt = 0;
    set<int> S;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (S.count(x) != 0)
            continue;
        S.insert(x);
        a[++cnt] = x;
    }
    if (cnt == 1)
    {
        cout << "-1\n";
        return;
    }
    int xx;
    sort(a + 1, a + cnt + 1);
    xx = a[2] - a[1];
    for (int i = 3; i <= cnt; i++)
    {
        xx = __gcd(xx, a[i] - a[i - 1]);
    }
    cout << xx << '\n';
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