/*
 * @Author: NEFU AB-IN
 * @Date: 2022-12-09 20:57:54
 * @FilePath: \Acwing\3765\3765.cpp
 * @LastEditTime: 2022-12-09 21:06:46
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
    string val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
  public:
    string expressionTree(TreeNode *root)
    {
        string ans;
        string f = "+-*/";
        function<void(TreeNode *)> dfs = [&](TreeNode *root) {
            if (!root)
                return;
            if (root->val == "+" || root->val == "-" || root->val == "*" || root->val == "/")
                ans += "(";
            dfs(root->left);
            ans += root->val;
            dfs(root->right);
            if (root->val == "+" || root->val == "-" || root->val == "*" || root->val == "/")
                ans += ")";
        };
        dfs(root);
        return ans.substr(1, ans.size() - 2);
    }
};

signed main()
{
    IOS;

    return 0;
}