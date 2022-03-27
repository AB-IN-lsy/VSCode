/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-27 11:03:59
 * @FilePath: \ACM\Contest\i.cpp
 * @LastEditTime: 2022-03-27 11:23:04
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
#define lowbit(x) x & -x

const int N = 2e5 + 10;
int tr[N], a[N], c[N];

void add(int x, int d)
{
    for (int i = x; i < N; i += lowbit(i))
    {
        tr[i] += d;
        c[i] += x * d;
    }
}
int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += (x + 1) * tr[i] - c[i];
    return res;
}

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], add(i, a[i] - a[i - 1]);
    int ceng = pow(2, log2(n) + 1) - 1;
    for (int i = 1; i <= m; i++)
    {
        int l, r, d;
        cin >> l >> r >> d;
        add(l, d), add(r + 1, -d);
        cout << ceng * (query(n) - query(0)) << '\n';
    }
    return 0;
}