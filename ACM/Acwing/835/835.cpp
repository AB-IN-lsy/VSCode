/*
 * @Author: NEFU AB-IN
 * @Date: 2023-02-26 10:36:48
 * @FilePath: \Acwing\835\835.cpp
 * @LastEditTime: 2023-02-26 23:02:31
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

int son[N][26], cnt[N], idx;

void insert(string s)
{
    int p = 0;
    for (int i = 0; i < SZ(s); ++i)
    {
        int u = s[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string s)
{
    int p = 0;
    for (int i = 0; i < SZ(s); ++i)
    {
        int u = s[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

signed main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        char op;
        string s;
        cin >> op >> s;
        if (op == 'I')
            insert(s);
        else
            cout << query(s) << '\n';
    }
    return 0;
}