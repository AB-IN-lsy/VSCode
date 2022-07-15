// Problem: H. Gambling
// Contest: Codeforces Round #799 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-06-29 22:47:34
// URL: https://codeforces.com/contest/1692/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    // map<int, vector<int>> b; // 会被卡unordered_map

    unordered_map<int, vector<int>, custom_hash> b; // 手写hash也可以

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[a[i]].emplace_back(i);
    }
    int mx = 0, l = 0, r = 0, res = a[0];
    for (auto [x, v] : b)
    {
        int s = v[0], last = v[0], ans = 1;
        for (int i = 1; i < SZ(v); ++i)
        {

            int num = v[i] - last - 1;
            last = v[i];

            ans -= num; // 减去中间值
            ans++;      // 加上下一值
            if (ans < 1)
            { // 如果ans < 1，那么就要有新的开始
                s = v[i];
                ans = 1;
            }

            if (mx < ans)
            {
                mx = ans;
                l = s;
                r = last;
                res = x;
            }
        }
    }
    cout << res << " " << l + 1 << " " << r + 1 << "\n";

    return;
}

int32_t main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}