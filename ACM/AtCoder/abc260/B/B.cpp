/*
 * @Author: NEFU AB-IN
 * @Date: 2022-07-17 20:08:24
 * @FilePath: \abc260\B\B.cpp
 * @LastEditTime: 2022-07-17 20:31:26
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int INF = INT_MAX;
const int N = 1e6 + 10;

struct sa
{
    int math, eng, id;
};

signed main()
{
    IOS;
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<sa> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].math;
        a[i].id = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].eng;
    }

    auto cmp1 = [&](sa p, sa q) {
        if (p.math != q.math)
            return p.math > q.math;
        else
            return p.id < q.id;
    };

    auto cmp2 = [&](sa p, sa q) {
        if (p.eng != q.eng)
            return p.eng > q.eng;
        else
            return p.id < q.id;
    };

    auto cmp3 = [&](sa p, sa q) {
        if (p.math + p.eng != q.math + q.eng)
            return p.math + p.eng > q.math + q.eng;
        else
            return p.id < q.id;
    };

    sort(a.begin() + 1, a.end(), cmp1);
    vector<int> st(n + 1), ans;

    int i = 1;
    while (x)
    {
        if (st[a[i].id])
        {
            i++;
            continue;
        }

        st[a[i].id] = 1;
        x--;
        ans.emplace_back(a[i].id);
        i++;
    }

    i = 1;
    sort(a.begin() + 1, a.end(), cmp2);
    while (y)
    {
        if (st[a[i].id])
        {
            i++;
            continue;
        }
        st[a[i].id] = 1;
        y--;
        ans.emplace_back(a[i].id);
        i++;
    }

    sort(a.begin() + 1, a.end(), cmp3);

    i = 1;
    while (z)
    {
        if (st[a[i].id])
        {
            i++;
            continue;
        }
        st[a[i].id] = 1;
        z--;
        ans.emplace_back(a[i].id);
        i++;
    }

    sort(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << '\n';

    return 0;
}