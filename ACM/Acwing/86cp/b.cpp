/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-14 18:59:43
 * @FilePath: \Acwing\86cp\b.cpp
 * @LastEditTime: 2023-01-14 19:16:22
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

unordered_map<int, bool> shu, heng;

signed main()
{
    IOS;
    int n, m, cnt = 0;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        int sum = 0;
        // 首先处理横轴
        if (!heng[x])
        {
            sum += (n - SZ(shu));
        }
        if (!shu[y])
        {
            sum += (n - SZ(heng));
        }
        cnt += sum;
        cout << n * n - cnt << " ";
        heng[x] = true;
        shu[y] = true;
    }

    return 0;
}