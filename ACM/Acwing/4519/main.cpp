/*
 * @Author: NEFU AB-IN
 * @Date: 2022-07-27 21:08:06
 * @FilePath: \Acwing\4519\main.cpp
 * @LastEditTime: 2022-07-27 21:08:30
 */
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 15;

int n;
int w[N];
bool st[N];
int ans;

bool check(int x)
{
    int r = sqrt(x);
    return r * r == x;
}

void dfs(int u, int last)
{
    if (u == n)
        ans++;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (st[i])
                continue; // 被用过了
            if (i && !st[i - 1] && w[i] == w[i - 1])
                continue;
            if (!check(last + w[i]))
                continue;

            st[i] = true;
            dfs(u + 1, w[i]);
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    sort(w, w + n);

    for (int i = 0; i < n; i++)
        if (!i || w[i] != w[i - 1])
        {
            st[i] = true;
            dfs(1, w[i]);
            st[i] = false;
        }

    cout << ans << endl;
    return 0;
}