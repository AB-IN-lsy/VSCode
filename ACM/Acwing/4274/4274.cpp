/*
 * @Author: NEFU AB-IN
 * @Date: 2022-06-21 09:49:36
 * @FilePath: \ACM\Acwing\4274\4274.cpp
 * @LastEditTime: 2022-06-21 10:24:53
 */
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

const int INF = INT_MAX;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    int n;
    cin >> n;

    vector<int> ls(n + 1), rs(n + 1);
    vector<string> e(n + 1);
    vector<int> deg(n + 1); // 入度

    for (int i = 1; i <= n; ++i)
    {
        string s;
        int l, r;
        cin >> s >> l >> r;
        if (l != -1)
            ls[i] = l, deg[l]++;
        if (r != -1)
            rs[i] = r, deg[r]++;
        e[i] = s;
    }
    int root = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (!deg[i])
        {
            root = i;
            break;
        }
    }
    function<void(int)> dfs = [&](int u) {
        cout << "(";
        if (ls[u] && rs[u])
        {
            dfs(ls[u]);
            dfs(rs[u]);
            cout << e[u];
        }
        else if (!ls[u] && !rs[u])
        {
            cout << e[u];
        }
        else
        {
            cout << e[u];
            dfs(rs[u]);
        }

        cout << ")";
    };

    dfs(root);

    return 0;
}