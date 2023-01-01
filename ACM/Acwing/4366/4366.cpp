/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-01 20:33:22
 * @FilePath: \Acwing\4366\4366.cpp
 * @LastEditTime: 2023-01-01 20:57:14
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

#undef int

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);

    vector<int> b;
    for (int i = 1; i * i <= sum; ++i)
    {
        if (sum % i == 0)
        {
            b.push_back(i);
            if (i * i != sum)
                b.push_back(sum / i);
        }
    }
    if (!SZ(b))
    {
        cout << "0\n";
        return;
    }
    sort(b.begin(), b.end());

    auto fun = [&](int x) {
        int cnt = 0, tmp = 0, flag = 0;
        for (int i = 0; i < n; ++i)
        {
            if (flag)
                cnt++;
            tmp += a[i];
            flag = 1;
            if (tmp == x)
                tmp = 0, flag = 0;
            if (tmp > x)
                return INT_MAX;
        }
        return cnt;
    };

    int ans = INT_MAX;
    for (auto x : b)
    {
        ans = min(ans, fun(x));
    }
    cout << ans << '\n';
    return;
}

signed main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}