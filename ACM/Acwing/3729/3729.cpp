/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-14 21:37:04
 * @FilePath: \Acwing\3729\3729.cpp
 * @LastEditTime: 2023-02-14 22:18:33
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

const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int a[N], b[N];

int n;
void solve()
{
    scanf("%d", &n);
    memset(b, 0, (n + 1) * 4);
    // for (int i = 1; i <= n; ++i)
    //     b[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        b[max(1, i - a[i] + 1)]++;
        b[i + 1]--;
    }
    for (int i = 1; i <= n; ++i)
    {
        b[i] += b[i - 1];
        printf("%d ", b[i] ? 1 : 0);
    }
    printf("\n");
    return;
}

signed main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}