/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-05 20:25:14
 * @FilePath: \LeetCode\1342\1342.cpp
 * @LastEditTime: 2022-09-05 20:28:25
 */
#include <bits/stdc++.h>
using namespace std;

// ---------------------
#define N n + 100
#define SZ(X) ((int)(X).size())
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

static int IOS = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int numberOfSteps(int num)
    {
        int ans = -1;
        function<void(int)> dfs = [&](int x) {
            ans++;
            if (!x)
                return;
            if (x & 1)
                dfs(x - 1);
            else
                dfs(x / 2);
        };
        dfs(num);
        return ans;
    }
};

// ---------------------

signed main()
{
    Solution solution;
    return 0;
}