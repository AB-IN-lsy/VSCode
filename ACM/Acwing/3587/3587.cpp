/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-11 09:01:11
 * @FilePath: \Acwing\3587\3587.cpp
 * @LastEditTime: 2022-08-11 09:21:05
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
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> fa(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            fa[i] = i;
        }
        function<int(int)> find = [&](int x) {
            if (fa[x] != x)
                return fa[x] = find(fa[x]);
            return fa[x];
        };
        for (int i = 1; i <= m; ++i)
        {
            int x, y;
            cin >> x >> y;
            fa[find(x)] = find(y);
        }
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (fa[i] == i)
                res++;
        }
        res == 1 ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}