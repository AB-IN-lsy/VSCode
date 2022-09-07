/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-07 16:17:31
 * @FilePath: \LeetCode\1379\1379.cpp
 * @LastEditTime: 2022-09-07 16:20:48
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
  public:
    TreeNode *ans = new TreeNode();
    void dfs(TreeNode *root, int val)
    {
        if (!root)
            return;

        if (root->val == val)
        {
            ans = root;
            return;
        }
        dfs(root->left, val);
        dfs(root->right, val);
    }
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {

        dfs(cloned, target->val);
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