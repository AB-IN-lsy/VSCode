/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-13 18:28:44
 * @FilePath: \Acwing\4700.1\4700.1.cpp
 * @LastEditTime: 2023-01-13 18:46:23
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

const int N = 35, M = 3e5 + 10, INF = 0x3f3f3f3f;

int n, x;
int w[N];
bool f[M];

signed main()
{
    IOS;
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> w[i];

    f[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = M; j >= w[i]; --j)
        {
            f[j] |= f[j - w[i]];
        }
    }
    for (int i = x; i <= M; ++i)
    {
        if (f[i])
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}