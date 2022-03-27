/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-27 12:16:01
 * @FilePath: \ACM\Contest\f.cpp
 * @LastEditTime: 2022-03-27 12:34:36
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 1e6 + 20;
int x[N], y[N], n;
double p[N];

int cale(int x1, int y1, int x2, int y2)
{
    return x1 * y2 - y1 * x2;
}

void solve()
{
    double tmp = 0.0, ans = 0.0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            tmp = p[i] * p[j] * cale(x[i], y[i], x[j], y[j]);
            for (int q = 1; q <= n; ++q)
            {
                if (q != i && q != j)
                {
                    if ((y[q] - y[i]) * (x[j] - x[i]) - (x[q] - x[i]) * (y[j] - y[i]) < 0)
                    {
                        tmp *= (1.0 - p[q]);
                    }
                }
            }
            ans += tmp;
        }
    }
    printf("%.6f", abs(ans / 2.0));
}
signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld%lld%lf", &x[i], &y[i], &p[i]);
    }
    solve();
    return 0;
}