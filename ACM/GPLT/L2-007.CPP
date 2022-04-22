/*
 * @Author: NEFU AB-IN
 * @Date: 2022-04-20 16:30:11
 * @FilePath: \ACM\GPLT\L2-007.CPP
 * @LastEditTime: 2022-04-20 17:14:52
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

const int N = 1e5 + 10;

int p[N], c[N], hn[N], hs[N], st[N];
struct sa
{
    int a, b;
} g[N];

struct Family
{
    int id, cnt, hn, hs;
};

int cnt;

int find(int x)
{
    if (x != p[x])
    {
        p[x] = find(p[x]);
    }
    return p[x];
}

signed main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int id, fa, ma, k;
        cin >> id >> fa >> ma >> k;
        st[id] = 1;
        if (fa != -1)
            g[cnt++] = {id, fa}, st[fa] = 1;
        if (ma != -1)
            g[cnt++] = {id, ma}, st[ma] = 1;
        for (int j = 1; j <= k; ++j)
        {
            int son;
            cin >> son;
            g[cnt++] = {id, son};
            st[son] = 1;
        }
        cin >> hn[id] >> hs[id];
    }
    for (int i = 0; i < N; ++i)
        p[i] = i, c[i] = 1;
    for (int i = 0; i < cnt; ++i)
    {
        int pa = find(g[i].a), pb = find(g[i].b);
        if (pa != pb)
        {
            if (pb > pa)
                swap(pa, pb);
            p[pa] = pb;
            c[pb] += c[pa];
            hn[pb] += hn[pa];
            hs[pb] += hs[pa];
        }
    }

    vector<Family> f;
    for (int i = 0; i < N; ++i)
    {
        if (p[i] == i && st[i])
        {
            f.push_back({i, c[i], hn[i], hs[i]});
        }
    }
    sort(f.begin(), f.end(), [&](Family a, Family b) {
        if (a.hs * b.cnt != b.hs * a.cnt)
            return a.hs * b.cnt > b.hs * a.cnt;
        return a.id < b.id;
    });
    printf("%lld\n", SZ(f));
    for (auto [id, cnt1, hn1, hs1] : f)
    {
        printf("%04lld %lld %.3lf %.3lf\n", id, cnt1, 1.0 * hn1 / cnt1, 1.0 * hs1 / cnt1);
    }

    return 0;
}