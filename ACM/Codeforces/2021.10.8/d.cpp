/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-08 21:20:00
 * @FilePath: \ACM\CF\2021.10.8\d.cpp
 * @LastEditTime: 2021-10-08 21:36:25
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
int ans[N], cnt[N];
signed main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        ans[a]++;
        ans[a + b]--;
    }
    for (int i = 1; i <= 400000; ++i)
    {
        ans[i] += ans[i - 1];
    }
    for (int i = 1; i <= 400000; ++i)
    {
        cnt[ans[i]]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << cnt[i] << ' ';
    }
    return 0;
}