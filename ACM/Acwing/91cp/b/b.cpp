/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-18 18:59:30
 * @FilePath: \Acwing\91cp\b\b.cpp
 * @LastEditTime: 2023-02-18 19:10:40
 */
/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-18 18:59:30
 * @FilePath: \Acwing\91cp\b\b.cpp
 * @LastEditTime: 2023-02-18 19:10:33
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

const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int p[N], sum[N];
signed main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        p[a]++;
        p[b + 1]--;
    }
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + p[i];
        if (sum[i] != 1)
        {
            cout << i << " " << sum[i];
            return 0;
        }
    }
    cout << "OK";
    return 0;
}