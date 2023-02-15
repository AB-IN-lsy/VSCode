/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-19 17:35:45
 * @FilePath: \ACM\GPLT\L2-003.CPP
 * @LastEditTime: 2022-04-19 17:59:52
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
const int N = 1010;
struct sa
{
    long double v, w;
};
long double w[N], v[N];

int n, m;
signed main()
{
    IOS;
    vector<sa> g;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i)
    {
        long double x;
        cin >> x;
        w[i] = x / v[i];
        g.push_back(sa{v[i], w[i]});
    }

    sort(g.begin(), g.end(), [&](sa a, sa b) { return a.w > b.w; });
    long double ans = 0;
    for (auto [v, w] : g)
    {
        if (v <= m)
        {
            ans += v * w;
            m -= v;
        }
        else
        {
            ans += m * w;
            break;
        }
    }
    printf("%.2Lf", ans);

    return 0;
}