/*
 * @Author: NEFU AB-IN
 * @Date: 2022-06-22 17:28:29
 * @FilePath: \ACM\Acwing\4278\4278.cpp
 * @LastEditTime: 2022-06-22 17:38:09
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 220;

int st[N][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        st[a][b] = st[b][a] = 1;
    }
    int k;
    cin >> k;

    auto solve = [&](int _) {
        int l, flag = 1;
        cin >> l;
        vector<int> q(l);
        vector<int> vis(n + 1);
        for (int i = 0; i < l; ++i)
        {
            cin >> q[i];
            vis[q[i]] = 1;
        }
        for (int i = 0; i < l; ++i)
        {
            for (int j = i + 1; j < l; ++j)
            {
                if (!st[q[i]][q[j]] && !st[q[j]][q[i]])
                {
                    printf("Area %d needs help.\n", _);
                    return;
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            int flag1 = 1;
            for (auto j : q)
            {
                if (!st[i][j] && !st[j][i])
                {
                    flag1 = 0;
                    break;
                }
            }
            if (flag1 && !vis[i])
            {
                printf("Area %d may invite more people, such as %d.\n", _, i);
                return;
            }
        }

        printf("Area %d is OK.\n", _);
        return;
    };

    for (int _ = 1; _ <= k; ++_)
    {
        solve(_);
    }
    return 0;
}