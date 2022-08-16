/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-11 12:23:10
 * @FilePath: \Acwing\3540\test.cpp
 * @LastEditTime: 2022-08-13 09:15:11
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 110;

int n;
int l[N], r[N], w[N], idx;
int root;

void insert(int &u, int x)
{
    if (!u)
        u = ++idx, w[u] = x;
    else if (x < w[u])
        insert(l[u], x);
    else if (x > w[u])
        insert(r[u], x);
}

void dfs(int u, int t)
{
    if (!u)
        return;
    if (t == 0)
        cout << w[u] << ' ';
    dfs(l[u], t);
    if (t == 1)
        cout << w[u] << ' ';
    dfs(r[u], t);
    if (t == 2)
        cout << w[u] << ' ';
}

int main()
{
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        insert(root, x);
    }

    for (int i = 0; i < 3; i++)
    {
        dfs(root, i);
        cout << endl;
    }

    return 0;
}
