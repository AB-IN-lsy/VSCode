/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-30 11:32:05
 * @FilePath: \Acwing\3384\3384.cpp
 * @LastEditTime: 2023-04-18 19:35:05
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

const int N = 1e2 + 10, INF = 0x3f3f3f3f;

unordered_map<char, char> l, r;
int id;
string s;

// 根据节点的值进行建树，而不是节点的下标
char dfs()
{
    char rt = s[++id];
    if (rt == '#' || id >= SZ(s))
        return '1';
    l[rt] = dfs();
    r[rt] = dfs();
    return rt;
}

void dfs2(char root)
{
    if (root == '1')
        return;
    dfs2(l[root]);
    cout << root << " ";
    dfs2(r[root]);
    return;
}

signed main()
{
    cin >> s;
    s = " " + s;

    char root = dfs();
    dfs2(root);
    return 0;
}
