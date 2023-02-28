/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-18 12:21:32
 * @FilePath: \Acwing\97\97.1.cpp
 * @LastEditTime: 2023-02-19 11:36:53
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

int sum(int p, int k)
{
    if (k == 0)
        return 1;
    if (k % 2 == 0)
        return sum(p, k - 1) % MOD + quickmod(p, k) % MOD;
    return sum(p, k / 2) % MOD * (1 + quickmod(p, k / 2 + 1)) % MOD;
}

int main()
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

    for (auto [x, cnt] : mp)
    {
        ans = ans * sum(x, cnt * b) % MOD;
    }
    cout << ans;
    return 0;
}