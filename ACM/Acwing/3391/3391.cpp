/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-17 09:36:14
 * @FilePath: \Acwing\3391\3391.cpp
 * @LastEditTime: 2022-08-17 09:58:22
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

signed main()
{
    IOS;
    int y, m, d;
    while (cin >> y >> m >> d)
    {
        vector<int> month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        month[2] += ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
        int ans = 0;
        for (int i = 1; i < m; ++i)
            ans += month[i];
        cout << ans + d << '\n';
    }

    return 0;
}