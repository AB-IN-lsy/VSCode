/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-11 10:25:50
 * @FilePath: \Acwing\3715\3715.cpp
 * @LastEditTime: 2022-08-11 11:48:24
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define DEBUG(X) cout << #X << ": " << X << '\n'
#define lowbit(x) x & -x
typedef pair<int, int> PII;

const int INF = INT_MAX;

signed main()
{
    IOS;
    int n;
    cin >> n;
    const int N = n + 1;
    vector<int> a(N), tr(N);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    function<void(int, int)> add = [&](int x, int d) {
        int i = x;
        for (; i < N; i += lowbit(i))
        {
            tr[i] += d;
        };
    };
    function<int(int)> query = [&](int x) {
        int i = x, res = 0;
        for (; i > 0; i -= lowbit(i))
        {
            res += tr[i];
        }
        return res;
    };

    int res = 0;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        add(a[i], 1);
        int k = query(n) - query(a[i]);
        res += k;
        ans[a[i]] = k;
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << '\n' << res;

    return 0;
}