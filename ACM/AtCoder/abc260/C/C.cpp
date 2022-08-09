/*
 * @Author: NEFU AB-IN
 * @Date: 2022-07-17 20:39:13
 * @FilePath: \abc260\C\C.cpp
 * @LastEditTime: 2022-07-17 20:46:18
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    int n, x, y;
    cin >> n >> x >> y;
    int ans = 0;
    function<void(int, int)> dfs = [&](int n, int k) {
        if (n == 1)
            return;
        ans += (k * x * y);
        dfs(n - 1, k * (x + 1));
    };

    dfs(n, 1);
    cout << ans << '\n';
    return 0;
}