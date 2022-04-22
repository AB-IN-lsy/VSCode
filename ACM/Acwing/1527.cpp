/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-19 21:23:13
 * @FilePath: \ACM\Acwing\1527.cpp
 * @LastEditTime: 2022-04-19 21:45:45
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

const int N = 1010;
int preorder[N], inorder[N], postorder[N];
int n, cnt;

bool build(int il, int ir, int pl, int pr, int op)
{
    if (il > ir)
        return true;

    int root = preorder[pl];
    int k;
    if (op == 0)
    {
        for (k = il; k <= ir; k++)
        {
            if (inorder[k] == root)
                break;
        }
        if (k > ir)
            return false;
    }
    else
    {
        for (k = ir; k >= il; k--)
        {
            if (inorder[k] == root)
                break;
        }
        if (k < il)
            return false;
    }
    bool res = true;
    if (!build(il, k - 1, pl + 1, pl + 1 + k - 1 - il, op))
        res = false;
    if (!build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr, op))
        res = false;

    postorder[cnt++] = root;
    return res;
}

signed main()
{
    IOS;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> preorder[i], inorder[i] = preorder[i];
    sort(inorder, inorder + n);
    if (build(0, n - 1, 0, n - 1, 0))
    {
        puts("YES");
        for (int i = 0; i < n; ++i)
        {
            cout << postorder[i] << " "[i == n - 1];
        }
    }
    else
    {
        reverse(inorder, inorder + n);
        cnt = 0; // 已经进行过一次build了，需要清0
        if (build(0, n - 1, 0, n - 1, 1))
        {
            puts("YES");
            for (int i = 0; i < n; ++i)
            {
                cout << postorder[i] << " "[i == n - 1];
            }
        }
        else
            puts("NO");
    }
    return 0;
}