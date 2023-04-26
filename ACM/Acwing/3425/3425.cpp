/*
 * @Author: NEFU AB-IN
 * @Date: 2023-04-25 16:20:00
 * @FilePath: \Acwing\3425\3425.cpp
 * @LastEditTime: 2023-04-25 17:35:59
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

struct sa
{
    int num;
    string color;

    bool operator<(const sa a)
    {
        return num > a.num;
    }
};

sa a[N];

signed main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].num >> a[i].color;
    }
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; ++i)
    {
        cout << a[i].color << '\n';
    }
    return 0;
}