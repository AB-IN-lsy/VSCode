/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-12 20:40:48
 * @FilePath: \GPLT\A1086\A1086.cpp
 * @LastEditTime: 2022-09-12 21:01:05
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

// #undef N
// const int N = 1e5 + 10;

// #undef int

signed main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> pre, in;
    stack<int> stk;
    for (int i = 1; i <= 2 * n; ++i)
    {
        string s;
        int x;
        cin >> s;
        if (s == "Push")
        {
            cin >> x;
            stk.push(x);
            pre.push_back(x);
        }
        else
        {
            in.push_back(stk.top());
            stk.pop();
        }
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        mp[in[i]] = i;
    }

    vector<int> post;
    function<void(int, int, int, int)> dfs = [&](int pl, int pr, int il, int ir) {
        int root = pre[pl];
        int k = mp[root];

        if (k - 1 >= il)
            dfs(pl + 1, pl + 1 + k - 1 - il, il, k - 1);
        if (ir >= k + 1)
            dfs(pl + 1 + k - 1 - il + 1, pr, k + 1, ir);

        post.push_back(root);
    };

    dfs(0, n - 1, 0, n - 1);

    cout << post[0];
    for (int i = 1; i < SZ(post); ++i)
        cout << " " << post[i];
    return 0;
}