/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-29 10:41:17
 * @FilePath: \LeetCode\654\654.cpp
 * @LastEditTime: 2022-08-29 22:51:07
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
  public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        stack<TreeNode *> stk;
        for (int x : nums)
        {
            auto node = new TreeNode(x);
            while (SZ(stk) && stk.top()->val < x)
            {
                node->left = stk.top(); // 每次都指，while每次更新，最后的就是最优的
                stk.pop();
            }
            if (SZ(stk))
                stk.top()->right = node;
            stk.push(node);
        }

        while (SZ(stk) > 1)
            stk.pop();
        return stk.top(); // 此时栈顶就是根
    }
};

// ---------------------

signed main()
{
    Solution solution;
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    solution.constructMaximumBinaryTree(nums);
    return 0;
}