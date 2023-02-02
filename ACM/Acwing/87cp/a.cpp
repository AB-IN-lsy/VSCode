/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-29 21:45:10
 * @FilePath: \Acwing\87cp\a.cpp
 * @LastEditTime: 2023-01-29 21:47:17
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
    IOS;
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            int x;
            cin >> x;
            if (x)
            {
                cout << abs(i - 3) + abs(j - 3);
                return 0;
            }
        }
    }
    return 0;
}