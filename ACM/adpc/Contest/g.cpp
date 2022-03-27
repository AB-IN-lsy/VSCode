/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-27 10:13:00
 * @FilePath: \ACM\Contest\g.cpp
 * @LastEditTime: 2022-03-27 17:07:56
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
const int INF = 0x3f3f3f3f;

int n, sum;

void dfs(int l, int r, int k)
{
    if (r > n)
        r = n;
    for (int i = l; i <= r; i++)
    {
        if (i != l && i % 10 == 0)
            return;
        sum++;
        if (sum <= k)
        {
            printf("%lld.mp4\n", i);
            if (sum == k)
                return;
        }
        if (i * 10 <= n)
            dfs(i * 10, i * 100 - 1, k);
    }
    return;
}
signed main()
{
    scanf("%lld", &n);
    dfs(1, 9, 50);
    return 0;
}