/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-19 19:59:50
 * @FilePath: \ACM\Acwing\43\c.cpp
 * @LastEditTime: 2022-03-19 23:16:31
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

#define lowbit(x) x & -x

const int N = 4e5 + 20;
LL tr[N], s[N], n, t;
vector<LL> xs(1, -INF);
LL ans;

void add(int x, int v)
{
    for (int i = x; i < N; i += lowbit(i))
    {
        tr[i] += v;
    }
}

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
    {
        res += tr[i];
    }
    return res;
}

int get(LL x)
{
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
}

signed main()
{
    IOS;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    for (int i = 0; i <= n; ++i)
    { // 0 <= j - 1 <= i - 1 , 1 <= i <= n
        xs.push_back(s[i]);
        xs.push_back(s[i] - t);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    add(get(s[0]), 1);
    for (int i = 1; i <= n; ++i)
    {
        ans += i - query(get(s[i] - t));
        add(get(s[i]), 1);
    }
    cout << ans << '\n';
    return 0;
}