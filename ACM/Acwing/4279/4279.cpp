/*
 * @Author: NEFU AB-IN
 * @Date: 2022-07-23 14:09:15
 * @FilePath: \Acwing\4279\4279.cpp
 * @LastEditTime: 2022-07-23 14:59:03
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
    vector<int> a(n), L(n), R(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    function<int(int, int)> dfs = [&](int l, int r) {
        if (l > r)
            return -1LL;
        int root = min_element(a.begin() + l, a.begin() + r + 1) - a.begin();
        L[root] = dfs(l, root - 1);
        R[root] = dfs(root + 1, r);
        return root;
    };

    int root = dfs(0, n - 1);

    queue<int> q;
    q.push(root);
    while (SZ(q))
    {
        auto t = q.front();
        q.pop();
        cout << a[t] << " ";
        if (L[t] != -1)
            q.push(L[t]);
        if (R[t] != -1)
            q.push(R[t]);
    }
    return 0;
}