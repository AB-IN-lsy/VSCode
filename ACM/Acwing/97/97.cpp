/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-18 11:22:46
 * @FilePath: \Acwing\97\97.cpp
 * @LastEditTime: 2023-02-18 23:11:41
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

const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 9901;

int quickmod(int a, int b)
{
    a %= MOD;
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b = b >> 1;
    }
    return res % MOD;
}

signed main()
{
    IOS;
    int a, b;
    cin >> a >> b;
    if (!a)
    {
        cout << 0;
        return 0;
    }
    // 质因子分解
    unordered_map<int, int> mp;
    for (int i = 2; i <= a / i; ++i)
    {
        while (a % i == 0)
        {
            mp[i]++;
            a /= i;
        }
    }
    if (a > 1)
        mp[a]++;
    int ans = 1;

    auto f = [&](int p, int n) {
        if ((p - 1) % MOD == 0)
            return n + 1;
        int pp = quickmod(p, n + 1);
        int ny = quickmod(p - 1, MOD - 2);
        return (pp - 1 + MOD) * ny % MOD;
    };

    for (auto [x, cnt] : mp)
    {
        ans = ans * f(x, cnt * b) % MOD;
    }
    cout << ans;
    return 0;
}
