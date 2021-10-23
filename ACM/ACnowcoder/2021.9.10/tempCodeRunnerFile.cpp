/*
 * @Author: NEFU AB_IN
 * @Date: 2021-09-11 10:27:58
 * @FilePath: \Vscode\ACM\NiuKe\2021.9.10\b.cpp
 * @LastEditTime: 2021-09-11 11:16:45
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int base = 131, N = 1e5 + 10;
ULL h[N], p[N] = {1}, g[N];

ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
ULL get1(int l, int r)
{
    return g[r] - g[l - 1] * p[r - l + 1];
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        h[0] = g[0] = 0;
        string m, c;
        int k;
        cin >> m >> c >> k;
        for (int i = 0; m[i]; ++i)
        {
            h[i] = h[i - 1] * base + m[i] - 'a';
            p[i] = p[i - 1] * base;
        }
        string hou = c.substr(SZ(c) - k, SZ(c));
        c = c.substr(0, SZ(c) - k);
        int flag = 0;
        string c_tmp = c;
        for (int i = 0; c[i]; ++i)
        {
            g[0] = 0;
            c_tmp.insert(i, hou);
            for (int j = 0; c_tmp[j]; ++j)
            {
                g[j] = g[j - 1] * base + c_tmp[j] - 'a';
            }
            if (get(0, SZ(m) - 1) == get1(0, SZ(c_tmp) - 1))
            {
                cout << "YES" << '\n';
                flag = 1;
                break;
            }
            c_tmp = c;
        }
        if (!flag)
            cout << "NO" << '\n';
    }
    return 0;
}