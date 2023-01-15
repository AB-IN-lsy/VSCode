/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-13 17:59:07
 * @FilePath: \Acwing\4700\4700.cpp
 * @LastEditTime: 2023-01-13 18:27:47
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

const int N = 35, INF = 0x3f3f3f3f;

int n, x;
int w[N];
int ans = INF;

void dfs(int u, int sum)
{
    if (ans == x || (ans > x && sum > ans)) // 如果有大于x的答案了，但此时sum还大于答案，就直接return
        return;

    if (sum >= x)
        ans = min(ans, sum);

    for (int i = u; i <= n; ++i)
        dfs(i + 1, sum + w[i]);
}

signed main()
{
    IOS;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];

    sort(w + 1, w + 1 + n);

    dfs(1, 0);
    cout << ans;
    return 0;
}