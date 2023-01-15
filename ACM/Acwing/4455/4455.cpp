/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-14 21:16:39
 * @FilePath: \Acwing\4455\4455.cpp
 * @LastEditTime: 2023-01-14 21:17:00
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
const int N = 2e5 + 10;

int n, m, k;
int d[N];

signed main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        int t, c;
        scanf("%d%d", &t, &c);
        d[max(1, t - k - c + 1)]++;
        d[max(1, t - k + 1)]--;
    }
    for (int i = 1; i <= N; i++)
    {
        d[i] += d[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        int q;
        scanf("%d", &q);
        printf("%d\n", d[q]);
    }
    return 0;
}