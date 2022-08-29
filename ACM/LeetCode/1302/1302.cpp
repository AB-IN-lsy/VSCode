/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-24 14:45:35
 * @FilePath: \LeetCode\1302\1302.cpp
 * @LastEditTime: 2022-08-24 14:57:26
 */
#include <bits/stdc++.h>
using namespace std;
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

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
    int deepestLeavesSum(TreeNode *root)
    {
        int d = 1, ans = 0;
        function<void(TreeNode *, int, int)> dfs = [&](TreeNode *root, int depth, int p) {
            if (root == nullptr)
                return;
            if (p == 1)
                d = max(d, depth);
            if (p == 2 && depth == d)
            {
                ans += root->val;
            }
            dfs(root->left, depth + 1, p);
            dfs(root->right, depth + 1, p);
        };
        dfs(root, 1, 1);
        dfs(root, 1, 2);
        return ans;
    }
};

signed main()
{
    IOS;

    return 0;
}