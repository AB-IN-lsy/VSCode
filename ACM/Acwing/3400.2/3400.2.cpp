/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-01 12:45:11
 * @FilePath: \Acwing\3400.2\3400.2.cpp
 * @LastEditTime: 2023-01-01 12:45:21
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

#undef N
const int N = 1e6 + 10;

// #undef int

int n, k, nn, p = 1, ans;

signed main()
{
    cin >> n >> k, nn = n;
    while (nn)
    {
        ans += n / p / 10 * p + max(min(n % (p * 10) - p * k + 1, p), 0LL);
        p *= 10, nn /= 10;
    }
    cout << ans;
    return 0;
}