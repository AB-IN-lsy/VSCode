/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-25 20:05:38
 * @FilePath: \ACM\Acwing\TMP.CPP
 * @LastEditTime: 2022-04-08 21:05:47
 */
#include <bits/stdc++.h>
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
using namespace std;

const int N = 2e5 + 10;

struct sa
{
    int l, r, len;
} a[N];

int last[30], lst[N];

int ans, n;

void dfs(int x, int len)
{
    len += a[x].len;
    if (lst[x])
        dfs(lst[x], len);
    ans = max(ans, len);
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        memset(lst, 0, sizeof lst);
        memset(last, 0, sizeof last);
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            a[i] = sa{s[0] - 'a', s[s.size() - 1] - 'a', (int)s.size()};
            lst[last[a[i].l]] = i;
            last[a[i].r] = i;
            // cout << a[i].l << ' ' << a[i].r << ' '<< a[i].len << '\n';
        }
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            dfs(i, 0);
        }

        cout << ans << '\n';
    }
}