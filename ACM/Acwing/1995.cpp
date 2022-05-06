/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-27 10:22:07
 * @FilePath: \ACM\Acwing\1995.cpp
 * @LastEditTime: 2022-04-27 10:52:34
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
int n, m, dis;
char op;

struct sa
{
    int dis;
    char op;
};

signed main()
{
    IOS;
    cin >> n >> m;
    deque<sa> a, b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> dis >> op;
        a.push_front({dis, op});
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> dis >> op;
        b.push_front({dis, op});
    }
    int posa = 0, posb = 0, ans = 0;
    int flag = 1;
    while (SZ(a) && SZ(b))
    {
        auto ta = a.back(), tb = b.back();
        a.pop_back();
        b.pop_back();
        ta.dis--;
        tb.dis--;
        if (ta.op == 'L')
            posa--;
        else
            posa++;
        if (tb.op == 'L')
            posb--;
        else
            posb++;
        if (posa == posb && !flag)
        {
            ans++;
            flag = 1;
        }
        if (posa != posb)
            flag = 0;
        if (ta.dis)
            a.push_back(ta);
        if (tb.dis)
            b.push_back(tb);
    }

    while (SZ(a))
    {
        auto ta = a.back();
        a.pop_back();
        ta.dis--;
        if (ta.op == 'L')
            posa--;
        else
            posa++;
        if (posa == posb)
            ans++;
        if (ta.dis)
            a.push_back(ta);
    }
    while (SZ(b))
    {
        auto tb = b.back();
        b.pop_back();
        tb.dis--;
        if (tb.op == 'L')
            posb--;
        else
            posb++;
        if (posa == posb)
            ans++;
        if (tb.dis)
            b.push_back(tb);
    }
    cout << ans;
    return 0;
}