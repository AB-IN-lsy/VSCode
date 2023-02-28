/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-23 23:58:49
 * @FilePath: \Acwing\831\831.cpp
 * @LastEditTime: 2023-02-24 00:03:22
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

int ne[N];
signed main()
{
    IOS;
    int n, m;
    string p, s;
    cin >> n >> p >> m >> s;

    p = " " + p;
    s = " " + s;
    for (int i = 2, j = 0; i <= n; ++i)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n)
        {
            cout << i - n << " ";
            j = ne[j];
        }
    }

    return 0;
}