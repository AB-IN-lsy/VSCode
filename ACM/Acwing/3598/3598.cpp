/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-11 09:48:09
 * @FilePath: \Acwing\3598\3598.cpp
 * @LastEditTime: 2022-08-11 10:22:14
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

signed main()
{
    IOS;
    string pre, in;

    while (cin >> pre >> in)
    {
        int n = SZ(pre);
        unordered_map<char, int> st;

        for (int i = 0; i < n; ++i)
        {
            st[in[i]] = i;
        }
        string post;
        function<void(int, int, int, int)> dfs = [&](int pl, int pr, int il, int ir) {
            char root = pre[pl];
            int k = st[root];
            if (il < k)
                dfs(pl + 1, pl + 1 + k - 1 - il, il, k - 1);
            if (ir > k)
                dfs(pl + 1 + k - 1 - il + 1, pr, k + 1, ir);
            post += root;
        };
        dfs(0, n - 1, 0, n - 1);

        cout << post << '\n';
    }
    return 0;
}