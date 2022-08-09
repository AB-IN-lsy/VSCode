/*
 * @Author: NEFU AB-IN
 * @Date: 2022-07-30 00:39:09
 * @FilePath: \Acwing\3588\3588.cpp
 * @LastEditTime: 2022-07-30 02:07:06
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

    function<int(int)> cale = [&](int x) {
        int cnt = 0;
        while (!(x & 1))
        {
            x >>= 1;
            cnt++;
        }

        return cnt;
    };

    while (cin >> n >> m, n != 0 && m != 0)
    {
        int ans = 0;

        for (int i = n - m + 1; i <= n; ++i)
        {
            ans += cale(i);
        }
        cout << ans << '\n';
    }

    return 0;
}