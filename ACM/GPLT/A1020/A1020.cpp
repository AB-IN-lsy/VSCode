/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-05 13:52:39
 * @FilePath: \GPLT\A1020\A1020.cpp
 * @LastEditTime: 2023-01-05 14:12:33
 */
#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
using namespace std;

const int N = 50;
int inod[N], postod[N], l[N], r[N];
int n;
unordered_map<int, int> order;

int bulid(int il, int ir, int pl, int pr)
{

    int root = postod[pr];
    int k = order[root];
    // 诀窍：
    // 1. 判断条件就是，中序遍历的两端点大小关系
    // 2. 后序遍历就从后往前看，用统一的标准，如 (ir - k - 1), 写的对的话，两句的长度是一样的
    if (ir >= k + 1)
        r[root] = bulid(k + 1, ir, pr - 1 - (ir - k - 1), pr - 1);
    if (il <= k - 1)
        l[root] = bulid(il, k - 1, pl, pr - 1 - (ir - k - 1) - 1);

    return root;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> postod[i];
    for (int i = 0; i < n; ++i)
    {
        cin >> inod[i];
        order[inod[i]] = i;
    }
    int root = bulid(0, n - 1, 0, n - 1);
    queue<int> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        ans.push_back(t);
        if (l[t])
            q.push(l[t]);
        if (r[t])
            q.push(r[t]);
    }
    for (int i = 0; i < SZ(ans); ++i)
        cout << ans[i] << " "[i == SZ(ans) - 1];
    return 0;
}