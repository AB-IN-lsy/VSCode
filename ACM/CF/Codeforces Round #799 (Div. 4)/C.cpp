// Problem: C. Where's the Bishop?
// Contest: Codeforces Round #799 (Div. 4)
// Author: NEFU AB-IN
// Edit Time:2022-06-15 23:46:49
// URL: https://codeforces.com/contest/1692/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f;
const int N = 10;

char a[N][N];

int dir[5][2] = {{0, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

void solve()
{
    for (int i = 1; i <= 8; ++i)
    {
        for (int j = 1; j <= 8; ++j)
        {
            cin >> a[i][j];
        }
    }
    auto judge = [&](int x, int y) {
        for (int i = 0; i < 5; ++i)
        {
            int x1 = x + dir[i][0];
            int y1 = y + dir[i][1];
            if (a[x1][y1] == '#' && x1 >= 1 && x1 <= 8 && y1 >= 1 && y1 <= 8)
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    };

    for (int i = 2; i <= 7; ++i)
    {
        for (int j = 2; j <= 7; ++j)
        {
            if (judge(i, j))
            {
                cout << i << " " << j << '\n';
                return;
            }
        }
    }

    return;
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}