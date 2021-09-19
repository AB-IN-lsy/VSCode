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
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int N = 1e3 + 10;
int a[N][N], row[N], col[N], flag[N][N], r[N], c[N];
LL k;

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        memset(col, 0x3f, sizeof col);
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> a[i][j];
                row[i] = max(row[i], a[i][j]);
                col[j] = min(col[j], a[i][j]);
            }
        }
        if (k == 1)
        {
            cout << row[1] << '\n';
        }
        else if (k & 1)
        {
            int maxx = 0x3f3f3f3f;
            for (int i = 1; i <= n; ++i)
            {
                maxx = min(maxx, row[i]);
            }
            cout << maxx << '\n';
        }
        else
        {
            int minn = 0;
            for (int i = 1; i <= m; ++i)
            {
                minn = max(minn, col[i]);
            }
            cout << minn << '\n';
        }
    }
    return 0;
}