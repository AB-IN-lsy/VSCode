/*
 * @Author: NEFU AB-IN
 * @Date: 2022-12-09 17:03:59
 * @FilePath: \Acwing\3766\3766.cpp
 * @LastEditTime: 2022-12-09 17:15:16
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
  public:
    int pathSum(TreeNode *root)
    {
        int sum = 0;
        function<void(TreeNode *, int)> dfs = [&](TreeNode *root, int depth) {
            if (!root->left && !root->right)
            {
                sum += depth * (root->val);
                return;
            }
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
            return;
        };

        dfs(root, 0);
        return sum;
    }
};

signed main()
{
    IOS;

    return 0;
}