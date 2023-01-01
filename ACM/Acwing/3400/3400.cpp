/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-01 12:16:23
 * @FilePath: \Acwing\3400\3400.cpp
 * @LastEditTime: 2023-01-01 12:18:20
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

// #undef N
// const int N = 1e5 + 10;

// #undef int

signed main()
{
    IOS;
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        auto f = [&](int x) {
            int res = 0;
            while (x)
            {
                if (x % 10 == k)
                    res++;
                x /= 10;
            }
            return res;
        };
        ans += f(i);
    }
    cout << ans;
    return 0;
}