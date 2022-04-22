/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-21 11:50:40
 * @FilePath: \ACM\GPLT\L2-015.CPP
 * @LastEditTime: 2022-04-21 11:57:22
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

vector<double> v;
int n, k, m;

signed main()
{
    IOS;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i)
    {
        double sum = 0.0, mn = INF, mx = -INF;
        for (int j = 1; j <= k; ++j)
        {
            double x;
            cin >> x;
            sum += x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        sum -= (mn + mx);
        v.push_back(1.0 * sum / (k - 2));
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = m - 1; i >= 0; --i)
    {
        printf("%.3f", v[i]);
        if (i > 0)
            printf(" ");
    }
    return 0;
}