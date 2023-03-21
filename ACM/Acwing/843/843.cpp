/*
 * @Author: NEFU AB-IN
 * @Date: 2023-03-01 09:15:32
 * @FilePath: \Acwing\843\843.cpp
 * @LastEditTime: 2023-03-01 09:15:54
 */
#include <iostream>

using namespace std;

const int N = 21;

int n;
bool r[N], c[N], d[N], ud[N];
char ans[N][N];

void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
                printf("%c", ans[i][j]);
            puts("");
        }
        puts("");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!c[i] && !d[x + i] && !ud[n - x + i])
        {
            ans[x][i] = 'Q';
            c[i] = d[x + i] = ud[n - x + i] = 1;
            dfs(x + 1);
            ans[x][i] = '.';
            c[i] = d[x + i] = ud[n - x + i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = '.';

    dfs(0);

    return 0;
}
