/*
 * @Author: NEFU AB-IN
 * @Date: 2022-06-20 21:45:36
 * @FilePath: \ACM\Acwing\4273.cpp
 * @LastEditTime: 2022-06-20 22:12:55
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

int e[N], ne[N];

signed main()
{
    int h1, h2, n;
    cin >> h1 >> h2 >> n;

    for (int i = 1; i <= n; ++i)
    {
        int addr, d, nxt;
        cin >> addr >> d >> nxt;
        e[addr] = d;
        ne[addr] = nxt;
    }

    // 统计结点
    vector<int> v1, v2;
    for (int i = h1; ~i; i = ne[i])
    {
        v1.push_back(i);
    }
    for (int i = h2; ~i; i = ne[i])
    {
        v2.push_back(i);
    }

    if (SZ(v1) > SZ(v2))
        swap(v1, v2);

    vector<int> ans;
    reverse(v1.begin(), v1.end());

    for (int i = 0, j = 0; i < SZ(v2); ++i)
    {
        ans.push_back(v2[i]);
        if (i & 1 && j < SZ(v1))
            ans.push_back(v1[j++]);
    }

    for (int i = 0; i < SZ(ans); ++i)
    {
        if (i < SZ(ans) - 1)
            printf("%05d %d %05d\n", ans[i], e[ans[i]], ans[i + 1]);
        else
            printf("%05d %d -1", ans[i], e[ans[i]]);
    }
    return 0;
}
