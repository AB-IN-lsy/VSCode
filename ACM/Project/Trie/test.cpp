/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-26 16:22:18
 * @FilePath: \Vscode\ACM\Project\Trie\test.cpp
 * @LastEditTime: 2021-09-04 22:02:35
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

namespace union_set
{
    const int N = 1e6 + 10;
    int fa[N], n;
    void init()
    {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }
    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void join(int a, int b)
    {
        int a1 = find(a), b1 = find(b);
        if (a1 != b1)
            fa[a1] = b1;
    }
}
using namespace union_set;

signed main()
{
    IOS;

    return 0;
}