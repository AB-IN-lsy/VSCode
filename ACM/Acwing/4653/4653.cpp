/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-04 09:14:03
 * @FilePath: \Acwing\4653\4653.cpp
 * @LastEditTime: 2023-01-04 09:26:51
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

struct sa
{
    int n, sum;
} a[N];

signed main()
{
    IOS;

    int n, m;
    cin >> n >> m;
    auto f = [&](int x) {
        int res = 0;
        while (x)
        {
            res += x % 10;
            x /= 10;
        }
        return res;
    };
    for (int i = 1; i <= n; ++i)
    {
        a[i].n = i;
        a[i].sum = f(i);
    }

    auto cmp = [&](const sa a, const sa b) {
        if (a.sum != b.sum)
            return a.sum < b.sum;
        else
            return a.n < b.n;
    };

    sort(a + 1, a + 1 + n, cmp);

    cout << a[m].n;

    return 0;
}