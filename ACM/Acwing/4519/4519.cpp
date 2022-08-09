/*
 * @Author: NEFU AB-IN
 * @Date: 2022-07-23 16:48:16
 * @FilePath: \Acwing\4519\4519.cpp
 * @LastEditTime: 2022-07-27 21:22:57
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

// 有重数组的不可重排列

signed main()
{
    IOS;
    int n;
    cin >> n;

    vector<int> a(n), st(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 0;
    function<bool(int)> check = [&](int x) {
        int y = sqrt(x);
        return y * y == x;
    };

    function<void(int, int)> dfs = [&](int u, int last) {
        if (u == n)
        {
            ans++;
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            if (st[i])
                continue; // 被标记了
            if (i && a[i] == a[i - 1] && !st[i - 1])
                continue; // 如果是和前一个数一样，但是前一个数都还没遍历，不符条件
            if (check(a[i] + last))
            {
                st[i] = 1;
                dfs(u + 1, a[i]);
                st[i] = 0;
            }
        }
    };

    for (int i = 0; i < n; ++i)
    {
        if (!i || a[i] != a[i - 1])
        {
            st[i] = 1;
            dfs(1, a[i]); // 挑选出每种数作为开头
            st[i] = 0;
        }
    }
    cout << ans << '\n';
    // int ans = 0;
    // do
    // {
    //     int flag = 1;
    //     for (int i = 0; i < n - 1; ++i)
    //     {
    //         if (!check(a[i] + a[i + 1]))
    //         {
    //             flag = 0;
    //             break;
    //         }
    //     }
    //     if (flag)
    //         ans++;
    // } while (next_permutation(a.begin(), a.end()));

    // cout << ans << '\n';
    return 0;
}