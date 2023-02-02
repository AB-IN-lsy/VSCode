/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-28 10:45:38
 * @FilePath: \Acwing\4729\4729.cpp
 * @LastEditTime: 2023-01-30 21:14:40
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
// #undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

signed main()
{
    IOS;
    int k, n, d, e;
    cin >> k;
    while (k--)
    {
        cin >> n >> d >> e;
        int m = n - e * d + 2;

        // p * q = n
        // p + q = m
        // 解一定是正整数
        // 找p
        int l = 1, r = m;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (mid * (m - mid) >= n)
                r = mid;
            else
                l = mid + 1;
        }
        if (l * (m - l) == n)
        {
            cout << l << " " << m - l << '\n';
        }
        else
            cout << "NO\n";
    }
    return 0;
}