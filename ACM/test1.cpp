#include <bits/stdc++.h>

using namespace std;
#define int long long
#define lowbit(x) x & -x
#define SZ(X) ((int)X.size())
const int N = 1e6 + 10;
int tr[N];
const int INF = 0x3f3f3f3f;
typedef pair<int, int> PII;

void add(int x)
{
    for (int i = x; i < N; i += lowbit(i))
    {
        tr[i] += 1;
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
vector<PII> g[N];
vector<int> alls = {-INF}; // 存储所有待离散化的值
signed main()
{
    int n;
    scanf("%lld", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        a[i]++;
        alls.push_back(a[i]);
    }
    // 离散化
    sort(alls.begin(), alls.end());                           // 将所有值排序
    alls.erase(unique(alls.begin(), alls.end()), alls.end()); // 去掉重复元素

    for (int i = 1; i <= n; ++i)
    {
        int id = lower_bound(alls.begin(), alls.end(), a[i]) - alls.begin();
        add(id);
        int num = (i - query(id - 1));
        g[id].push_back({num - i, i});
    }

    int ans = 0;
    for (auto lst : g)
    {
        sort(lst.begin(), lst.end());
        int l = 0, r = 0;
        while (l <= r && l < SZ(lst))
        {
            while (r < SZ(lst) && lst[l].first == lst[r].first)
                r++;
            ans = max(ans, lst[r - 1].second - lst[l].second);
            l = r;
        }
    }
    printf("%lld\n", ans);
    return 0;
}