/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-08 09:00:37
 * @FilePath: \GPLT\A1032\A1032.cpp
 * @LastEditTime: 2023-01-08 09:18:30
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int ne[N];
char w[N];

#undef int
int heada, headb, n;

signed main()
{
    scanf("%d%d%d", &heada, &headb, &n);
    for (int i = 1; i <= n; ++i)
    {
        int addr, addr_ne;
        char ww;
        scanf("%d %c %d", &addr, &ww, &addr_ne);
        w[addr] = ww;
        ne[addr] = addr_ne;
    }

    auto p = heada, q = headb;
    while (p != q)
    {
        p = (p != -1 ? ne[p] : headb);
        q = (q != -1 ? ne[q] : heada);
    }

    if (~p)
        printf("%05d", p);
    else
        printf("-1");

    return 0;
}