/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-09 13:25:38
 * @FilePath: \LeetCode\1387\1387.cpp
 * @LastEditTime: 2022-09-09 14:11:53
 */
#include <bits/stdc++.h>
using namespace std;

// ---------------------
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

// #undef N
// const int N = 1e5 + 10;

static int IOS = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    unordered_map<int, int> mp;
    int dfs(int x)
    {
        if (x == 1)
            return 0;
        if (x & 1)
            return mp[x] = 2 + dfs((3 * x + 1) / 2);
        else
            return mp[x] = 1 + dfs(x / 2);
    }

    int getKth(int lo, int hi, int k)
    {
        vector<PII> ans;
        for (int i = lo; i <= hi; ++i)
        {
            ans.push_back({dfs(i), i});
        }
        sort(ans.begin(), ans.end());
        return ans[k - 1].second;
    }
};

#undef int
// ---------------------

// signed main()
// {
//     Solution solution;
//     return 0;
// }