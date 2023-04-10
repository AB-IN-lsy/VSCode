/*
 * @Author: NEFU AB-IN
 * @Date: 2023-04-09 17:17:53
 * @FilePath: \Acwing\98cp\c\c.cpp
 * @LastEditTime: 2023-04-09 18:10:11
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

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

// n的阶乘有多少质因子p
int func(int n, int p)
{
    int ans = 0;
    while (n >= p)
    {
        ans += n / p;
        p *= p;
    }
    return ans;
}

signed main()
{
    IOS;
    int m;
    cin >> m;
    vector<int> v;
    for (int i = 1; i <= N; ++i)
    {
        int res = min(func(i, 2), func(i, 5));
        if (res == m)
            v.push_back(i);
        else if (res > m)
            break;
    }
    cout << SZ(v) << '\n';
    for (auto i : v)
        cout << i << " ";
    return 0;
}