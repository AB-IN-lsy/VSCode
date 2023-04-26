/*
 * @Author: NEFU AB-IN
 * @Date: 2023-04-18 20:00:24
 * @FilePath: \Acwing\4956\4956.cpp
 * @LastEditTime: 2023-04-20 12:06:02
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

const int N = 1e4 + 10, INF = 0x3f3f3f3f;
int a[N], b[N];
int n;

bool check(int x, int flag)
{
    for (int i = 1; i <= n; ++i)
    {
        if (flag == 1 && a[i] / x > b[i])
            return false;
        if (flag == 2 && a[i] / x < b[i])
            return false;
    }
    return true;
}

signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i];
    }

    // 最小值
    int l = 1, r = INF;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid, 1))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r << " ";

    // 最大值
    l = 1;
    r = INF;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid, 2))
            l = mid;
        else
            r = mid - 1;
    }
    cout << r;

    return 0;
}
