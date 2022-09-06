/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-05 21:10:01
 * @FilePath: \LeetCode\1345\1345.cpp
 * @LastEditTime: 2022-09-06 14:06:02
 */
#include <bits/stdc++.h>
using namespace std;

// ---------------------
#define N n + 100
#define SZ(X) ((int)(X).size())
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

// #undef N
// const int N = 1e5 + 10;

// #undef int;

static int IOS = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int minJumps(vector<int> &arr)
    {
        int n = SZ(arr);
        queue<PII> q;
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < n; ++i)
        {
            g[arr[i]].push_back(i);
        }

        vector<int> st(n);
        st[0] = 1;
        q.push({0, 0});

        while (SZ(q))
        {
            auto t = q.front();
            q.pop();

            int id = t.first, cnt = t.second;

            if (id == n - 1)
            {
                return cnt;
            }
            if (g.count(arr[id]))
            {
                for (auto v : g[arr[id]])
                {
                    if (!st[v])
                        q.push({v, cnt + 1}), st[v] = 1;
                }
                g.erase(arr[id]); // 遍历完一遍了，直接就可以删掉了
            }
            if (id >= 1 && !st[id - 1])
                q.push({id - 1, cnt + 1}), st[id - 1] = 1;
            if (id <= n - 1 && !st[id + 1])
                q.push({id + 1, cnt + 1}), st[id + 1] = 1;
        }
        return 0;
    }
};

// ---------------------

signed main()
{
    Solution solution;
    return 0;
}