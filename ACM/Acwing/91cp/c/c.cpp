/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-18 18:59:30
 * @FilePath: \Acwing\91cp\c\c.cpp
 * @LastEditTime: 2023-02-18 21:09:06
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

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> g(m + 1, vector<int>(n + 1));

    auto check = [&](int x) {
        vector<int> cnt1(n);
        vector<int> cnt2(m);

        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i < m; ++i)
            {
                if (g[i][j] >= x)
                {
                    cnt1[j] = 1;
                    cnt2[i] += 1;
                }
            }
            if (!cnt1[j])
                return false;
        }

        for (int i = 0; i < m; ++i)
        {
            if (cnt2[i] >= 2)
                return true;
        }
        return false;
    };

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];
    int l = 1, r = 1e9;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}