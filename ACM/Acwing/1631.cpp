/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-19 22:39:04
 * @FilePath: \ACM\Acwing\1631.cpp
 * @LastEditTime: 2022-04-19 22:50:00
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;
int preorder[N], inorder[N];
int n, post;

unordered_map<int, int> pos;

void build(int il, int ir, int pl, int pr)
{
    int root = preorder[pl];
    int k = pos[root];
    if (il < k)
        build(il, k - 1, pl + 1, pl + 1 + k - 1 - il);
    if (ir > k)
        build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr);
    if (!post)
        post = root;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    build(0, n - 1, 0, n - 1);
    cout << post;
}