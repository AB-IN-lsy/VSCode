/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-20 21:51:02
 * @FilePath: \Acwing\238\238.cpp
 * @LastEditTime: 2023-02-21 11:27:22
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

int fa[N], d[N], sz[N];

int find(int x)
{
    if (fa[x] != x)
    {
        int rt = find(fa[x]);
        d[x] += d[fa[x]];
        fa[x] = rt;
    }
    return fa[x];
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    for (int i = 1; i < N; ++i)
    {
        fa[i] = i;
        sz[i] = 1;
    }

    while (t--)
    {
        char q;
        int a, b;
        cin >> q >> a >> b;
        int ra = find(a), rb = find(b);
        if (q == 'M')
        {
            if (ra != rb)
            {
                fa[ra] = rb;
                d[ra] = sz[rb];
                sz[rb] += sz[ra];
            }
        }
        else
        {
            if (ra != rb)
                cout << "-1\n";
            else
                cout << max(0, abs(d[a] - d[b]) - 1) << '\n';
        }
    }
    return 0;
}