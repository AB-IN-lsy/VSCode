/*
 * @Author: NEFU AB-IN
 * @Date: 2022-12-27 18:48:47
 * @FilePath: \Acwing\4261\4261.cpp
 * @LastEditTime: 2023-01-01 11:34:16
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

// #undef int

signed main()
{
    IOS;
    string s;
    int n;
    cin >> n >> s;

    vector<int> l(n), r(n);

    int g = 0, h = 0;
    for (int i = 0; i < SZ(s); ++i)
    {
        if (s[i] == 'G')
            l[i] = h, h = 0, g++;
        else
            l[i] = g, g = 0, h++;
    }
    g = h = 0;
    for (int i = SZ(s) - 1; i >= 0; --i)
    {
        if (s[i] == 'G')
            r[i] = h, h = 0, g++;
        else
            r[i] = g, g = 0, h++;
    }
    int res = 0;
    for (int i = 0; i < SZ(s); ++i)
    {
        // cout << l[i] << " " << r[i] << '\n';
        res += (l[i] * r[i]) + max(l[i] - 1, 0LL) + max(r[i] - 1, 0LL);
    }
    cout << res;
    return 0;
}