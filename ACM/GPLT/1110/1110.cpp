/*
 * @Author: NEFU AB-IN
 * @Date: 2022-06-04 11:45:48
 * @FilePath: \ACM\GPLT\1110.cpp
 * @LastEditTime: 2022-06-04 12:59:12
 */
#include <bits/stdc++.h>
using namespace std;
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int N = 1e6 + 10;

int h, e[N], ne[N];
int n, k;
signed main()
{
    IOS;
    cin >> h >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        int addr, data, nxt;
        cin >> addr >> data >> nxt;
        e[addr] = data;
        ne[addr] = nxt;
    }
    vector<int> lst;
    int cnt = 0;
    for (int i = h; ~i; i = ne[i])
    {
        if (cnt == 0)
        {
            lst.push_back(i);
        }
        cnt += 1;
        if (cnt == k)
            cnt = 0;
    }
    vector<int> ans;
    reverse(lst.begin(), lst.end());
    for (auto addr : lst)
    {
        for (int i = addr, cnt = 0; ~i && cnt < k; i = ne[i], cnt++)
        {
            ans.push_back(i);
        }
    }
    for (int i = 0; i < SZ(ans); ++i)
    {
        if (i != SZ(ans) - 1)
            printf("%05d %d %05d\n", ans[i], e[ans[i]], ans[i + 1]);
        else
            printf("%05d %d -1\n", ans[i], e[ans[i]]);
    }
    return 0;
}