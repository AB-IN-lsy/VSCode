/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-18 13:37:49
 * @FilePath: \Vscode\ACM\Hdu\2021.9.18\b.cpp
 * @LastEditTime: 2021-09-18 17:27:33
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((LL)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<LL, LL> PII;

const LL N = 5e6 + 10;
LL row[N], col[N], r[N], c[N];
LL k;

signed main()
{
    IOS;
    LL t;
    cin >> t;
    while (t--)
    {
        LL n, m;
        memset(col, 0x3f, sizeof col);
        memset(row, 0, sizeof row);

        cin >> n >> m >> k;
        LL ans;
        for (LL i = 1; i <= n; ++i)
        {
            for (LL j = 1; j <= m; ++j)
            {
                LL x;
                cin >> x;
                if(i == 1 && j == 1) ans = x;
                row[i] = max(row[i], x);
                col[j] = min(col[j], x);
            }
        }
        if (k == 1)
        {
            cout << row[1] << '\n';
        }
        else if (k & 1)
        {
            LL maxx = 0x3f3f3f3f;
            for (LL i = 1; i <= n; ++i)
            {
                maxx = min(maxx, row[i]);
            }
            cout << max(maxx, ans) << '\n';
        }
        else
        {
            LL minn = 0;
            for (LL i = 1; i <= m; ++i)
            {
                minn = max(minn, col[i]);
            }
            cout << max(minn, ans) << '\n';
        }
    }
    return 0;
}