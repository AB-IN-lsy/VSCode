/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-20 22:34:10
 * @FilePath: \ACM\GPLT\L2-011.CPP
 * @LastEditTime: 2022-04-20 22:44:30
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

const int N = 60;
deque<int> q;
int preorder[N], inorder[N], n;
unordered_map<int, int> pos, lt, rt;
vector<int> v;

int build(int il, int ir, int pl, int pr)
{
    int root = preorder[pl];
    int k = pos[root];
    if (il < k)
        lt[root] = build(il, k - 1, pl + 1, pl + 1 + k - 1 - il);
    if (ir > k)
        rt[root] = build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr);
    return root;
}

void bfs(int root)
{
    q.push_front(root);
    while (q.size())
    {
        auto root = q.back();
        q.pop_back();
        v.push_back(root);
        if (rt[root])
            q.push_front(rt[root]);
        if (lt[root])
            q.push_front(lt[root]);
    }
}

signed main()
{
    IOS;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> preorder[i];
    }
    int root = build(0, n - 1, 0, n - 1);
    bfs(root);
    for (int i = 0; i < SZ(v); ++i)
    {
        cout << v[i] << " "[i == SZ(v) - 1];
    }
    return 0;
}