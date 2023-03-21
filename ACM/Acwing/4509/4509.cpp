/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-12 11:52:00
 * @FilePath: \Acwing\4509\4509.cpp
 * @LastEditTime: 2023-01-12 12:02:49
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

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    double avg = (double)accumulate(a.begin(), a.end(), 0) / n;

    double s = 0;
    for (int i = 0; i < n; ++i)
    {
        s += (a[i] - avg) * (a[i] - avg);
    }

    s /= (double)n;
    s = sqrt(s);

    for (int i = 0; i < n; ++i)
    {
        printf("%.17lf\n", (a[i] - avg) / s);
    }
    return 0;
}