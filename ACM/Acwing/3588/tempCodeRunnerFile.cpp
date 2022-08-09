/*
 * @Author: NEFU AB-IN
 * @Date: 2022-07-30 00:39:09
 * @FilePath: \Acwing\3588\tempCodeRunnerFile.cpp
 * @LastEditTime: 2022-07-30 12:32:14
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

    function<int(int, int)> cale = [&](int x, int p) {
        int cnt = 0;
        while (x)
            cnt += x /= p;
        return cnt;
    };

    while (cin >> n >> m, n != 0 && m != 0)
    {
        cout << cale(n, 2) - cale(n - m, 2) << '\n';
    }

    return 0;
}