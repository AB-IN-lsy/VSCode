/*
 * @Author: NEFU AB-IN
 * @Date: 2021-09-23 10:49:19
 * @FilePath: \ACM\test.cpp
 * @LastEditTime: 2021-10-15 20:04:53
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
LL n, k;
LL a[N];
signed main()
{
    IOS;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int tmp_k = k, cnt = n;
    while (k > 0)
    {
        k -= cnt;
        cnt -= 1;
    }
    cnt++;
    k += cnt;
    cnt = n - cnt;
    if (cnt == 1)
    {
        cout << a[tmp_k] << '\n';
    }
    else
    {
        int id = cnt - 1;
        cout << a[id] + a[id + k] << '\n';
    }
    return 0;
}