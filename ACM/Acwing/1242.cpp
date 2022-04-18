/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-05 15:59:55
 * @FilePath: \ACM\Acwing\1242.cpp
 * @LastEditTime: 2022-04-05 16:02:47
 */
#include <bits/stdc++.h>
#define MAXN 200001
#define INF 1000000007
#define fo(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int lson[MAXN * 30], rson[MAXN * 30], mn[MAXN * 30];
int root[MAXN];
int n, m, tot;

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void update(int &t, int old, int l, int r, int x, int y)
{
    t = ++tot;
    lson[t] = lson[old], rson[t] = rson[old], mn[t] = mn[old];
    if (l == r)
    {
        mn[t] = y;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
        update(lson[t], lson[old], l, mid, x, y);
    else
        update(rson[t], rson[old], mid + 1, r, x, y);
    mn[t] = min(mn[lson[t]], mn[rson[t]]);
}

int query(int t, int l, int r, int x)
{
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (mn[lson[t]] < x)
        return query(lson[t], l, mid, x);
    else
        return query(rson[t], mid + 1, r, x);
}

int main()
{
    n = read();
    fo(i, 1, n)
    {
        int x = read();
        update(root[i], root[i - 1], 1, n + 1, x + 1, i);
        printf("%d\n", query(root[i], 1, n + 1, 0) - 1);
    }
    return 0;
}