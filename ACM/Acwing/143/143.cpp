/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-27 08:59:31
 * @FilePath: \Acwing\143\143.cpp
 * @LastEditTime: 2023-02-27 09:32:48
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

const int N = 32 * (1e5 + 10), INF = 0x3f3f3f3f;

int idx, val[N], son[N][2];

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; --i)
    {
        int u = x >> i & 1;
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    val[p] = x;
}

int query(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; --i)
    {
        int u = x >> i & 1;
        if (son[p][u ^ 1])
        {
            p = son[p][u ^ 1];
        }
        else
            p = son[p][u];
    }
    return val[p] ^ x;
}

signed main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        res = max(res, query(a[i]));
    }
    cout << res;
    return 0;
}