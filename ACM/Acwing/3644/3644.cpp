/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-13 12:15:51
 * @FilePath: \Acwing\3644\3644.cpp
 * @LastEditTime: 2022-08-13 12:23:53
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

int st[1000], a[1000];

bool judge(int x)
{
    string s = to_string(x);
    int ans = 0;
    for (auto i : s)
    {
        ans += pow(i - '0', 3);
    }
    return ans == x;
}

void init()
{

    for (int i = 100; i <= 999; ++i)
    {
        if (judge(i))
            st[i] = 1;
        a[i] = a[i - 1] + st[i];
    }
    return;
}

signed main()
{
    IOS;
    init();
    int m, n;
    while (cin >> m >> n, m && n)
    {
        if (!(a[n] - a[m - 1]))
        {
            cout << "no\n";
        }
        else
        {
            for (int i = m; i <= n; ++i)
            {
                if (st[i])
                    cout << i << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}