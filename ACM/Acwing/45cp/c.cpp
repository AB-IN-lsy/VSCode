/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-02 19:59:19
 * @FilePath: \ACM\Acwing\45\c.cpp
 * @LastEditTime: 2022-04-02 20:15:12
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int N = 2020;
int a[N], b[N], lena[N], lenb[N];

signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    memset(lena, 0x3f, sizeof lena);
    memset(lenb, 0x3f, sizeof lenb);
    //计算a b数组的前缀和
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1];
    for (int i = 1; i <= m; i++)
        cin >> b[i], b[i] += b[i - 1];
    //记录a b数组长度为len时的最小区间和
    for (int len = 1; len <= n; len++)
    {
        for (int l = 1; l <= n - len + 1; l++)
        {
            int r = l + len - 1;
            lena[len] = min(lena[len], a[r] - a[l - 1]);
        }
    }
    for (int len = 1; len <= m; len++)
    {
        for (int l = 1; l <= m - len + 1; l++)
        {
            int r = l + len - 1;
            lenb[len] = min(lenb[len], b[r] - b[l - 1]);
        }
    }
    int x;
    cin >> x;
    int ans = 0;
    //暴力枚举元素和小于x时的最大数量
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (lena[i] * lenb[j] <= x)
                ans = max(ans, i * j);
        }
    cout << ans << '\N';
}