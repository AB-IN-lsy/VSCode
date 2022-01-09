/*
 * @Author: NEFU AB-IN
 * @Date: 2021-10-25 10:13:38
 * @FilePath: \ACM\test.cpp
 * @LastEditTime: 2022-01-07 21:35:15
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

struct sa
{
    int w, to;
    bool operator<(const sa &a) const
    {
        return w > a.w;
    }
};

sa a[100];

signed main()
{
    IOS;
    for (int i = 1; i <= 10; ++i)
    {
        cin >> a[i].w >> a[i].to;
    }
    sort(a + 1, a + 11);
    for (int i = 1; i <= 10; ++i)
    {
        cout << a[i].w << a[i].to << '\n';
    }
    return 0;
}