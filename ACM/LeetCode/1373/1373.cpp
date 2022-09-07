/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-07 15:44:15
 * @FilePath: \LeetCode\1373\1373.cpp
 * @LastEditTime: 2022-09-07 16:00:02
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
  public:
    int ans = 0;

    // 返回值: {min, max, sum, isBiSearchTree}
    vector<int> dfs(TreeNode *root)
    {
        if (!root)
            return {INT_MAX, INT_MIN, 0, true}; // 初始化
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int val = root->val;
        int sum = left[2] + right[2] + val;
        bool isB = false;

        if (val > left[1] && val < right[0])
        {
            if (left[3] && right[3])
                isB = true;
        }

        if (isB)
            ans = max(ans, sum);
        int mx = max({left[1], right[1], val});
        int mn = min({left[0], right[0], val});

        return {mn, mx, sum, isB};
    }

    int maxSumBST(TreeNode *root)
    {
        dfs(root);
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