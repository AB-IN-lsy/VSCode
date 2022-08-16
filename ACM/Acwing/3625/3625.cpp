/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-11 08:54:11
 * @FilePath: \Acwing\3625\3625.cpp
 * @LastEditTime: 2022-08-11 08:59:24
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
const int MOD = 233333;

signed main()
{
    IOS;
    int x, n;
    cin >> x >> n;

    function<int(int, int)> qp = [&](int a, int b) {
        int res = 1;
        while (b)
        {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    };

    cout << qp(x, n) << '\n';
    return 0;
}