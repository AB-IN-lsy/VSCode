/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-20 12:39:25
 * @FilePath: \ACM\GPLT\L2-006.CPP
 * @LastEditTime: 2022-04-20 12:55:38
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
int inorder[N], postorder[N], ans[N], cnt;
unordered_map<int, int> lt, rt, pos;
deque<int> q;

int build(int il, int ir, int pl, int pr)
{
    int root = postorder[pr];
    int k = pos[root];
    if (il < k)
        lt[root] = build(il, k - 1, pl, pl + k - 1 - il);
    if (ir > k)
        rt[root] = build(k + 1, ir, pl + k - 1 - il + 1, pr - 1);
    return root;
}

void bfs(int u)
{
    q.push_front(u);
    while (q.size())
    {
        auto u = q.back();
        q.pop_back();
        ans[cnt++] = u;
        if (lt.count(u))
            q.push_front(lt[u]);
        if (rt.count(u))
            q.push_front(rt[u]);
    }
}

signed main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> postorder[i];
    for (int i = 0; i < n; ++i)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    int root = build(0, n - 1, 0, n - 1);
    bfs(root);
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " "[i == n - 1];
    return 0;
}