/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-06 18:34:53
 * @FilePath: \LeetCode\1371\1371.cpp
 * @LastEditTime: 2022-09-07 16:34:40
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
    int findTheLongestSubstring(string s)
    {
        vector<int> st(32, -INT_MAX);
        // 一共 2^5 = 32种状态，初始化为负无穷，值为该状态最早的下标
        // 二进制 00001 代表 1，代表u为奇数，其他为偶数
        st[0] = -1; // 记录该下标的前一个，因为要进行前缀和操作
        string p = "aeiou";
        int state = 0; // 一开始都是偶数，即0
        int ans = 0;
        for (int i = 0; i < SZ(s); ++i)
        {
            int k = p.find(s[i]);
            if (k != -1)
                state ^= (1 << k); // state 的第k位异或1
            if (st[state] == -INT_MAX)
                // 说明还没更新过最小下标
                st[state] = i;
            else
                ans = max(ans, i - st[state]);
            // [j + 1, i] 即 i - (j + 1) + 1
        }
        return ans;
    }
};

#undef int
// ---------------------

signed main()
{
    Solution solution;
    return 0;
}