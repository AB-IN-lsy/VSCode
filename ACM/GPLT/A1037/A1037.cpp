/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-08 19:04:34
 * @FilePath: \GPLT\A1037\A1037.cpp
 * @LastEditTime: 2023-01-08 19:21:51
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
int nc, np;

signed main()
{
    IOS;
    cin >> nc;
    vector<int> c(nc);
    for (int i = 0; i < nc; ++i)
        cin >> c[i];
    cin >> np;
    vector<int> p(np);
    for (int i = 0; i < np; ++i)
        cin >> p[i];

    sort(ALL(c), greater<int>());
    sort(ALL(p), greater<int>());

    int res = 0;
    for (int i = 0, j = 0; i < nc && j < np && c[i] > 0 && p[j] > 0; ++i, ++j)
    {
        res += c[i] * p[j];
    }

    for (int i = nc - 1, j = np - 1; i >= 0 && j >= 0 && c[i] < 0 && p[j] < 0; --i, --j)
    {
        res += c[i] * p[j];
    }
    cout << res;

    return 0;
}