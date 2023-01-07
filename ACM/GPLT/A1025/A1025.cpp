/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-07 11:45:49
 * @FilePath: \GPLT\A1025\A1025.cpp
 * @LastEditTime: 2023-01-07 16:59:01
 */
#include <bits/stdc++.h>
using namespace std;
#define N n + 100
#define int long long
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

#undef N
const int N = 110;

#undef int

int n, k;
struct sa
{
    string id;
    int fr, loc, lr, gd;
    bool operator<(const sa &t) const
    {
        if (gd != t.gd)
            return gd > t.gd;
        return id < t.id;
    }
};

struct sb
{
    string id;
    int gd;

    bool operator<(const sb &t) const
    {
        if (gd != t.gd)
            return gd > t.gd;
        return id < t.id;
    }
};

vector<sb> g[N]; // 分组
vector<sb> gg;   // 总

unordered_map<string, sa> mp;
vector<sa> ans; // 总的结果

signed main()
{
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        string id;
        int gd;
        cin >> k;
        for (int j = 1; j <= k; ++j)
        {
            cin >> id >> gd;
            mp[id].loc = i;
            mp[id].gd = gd;
            g[i].push_back({id, gd});
            gg.push_back({id, gd});
        }
    }

    sort(gg.begin(), gg.end());
    for (int i = 1; i <= n; ++i)
    {
        sort(g[i].begin(), g[i].end());
    }

    for (auto &[id, t] : mp)
    {
        auto loc = t.loc; // 组别
        auto gd = t.gd;   // 成绩
        // 求分组内rank

        int l = 0, r = SZ(g[loc]) - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (g[loc][mid].gd <= gd)
                r = mid;
            else
                l = mid + 1;
        }
        mp[id].lr = l + 1;

        // 求总体rank
        l = 0, r = SZ(gg) - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (gg[mid].gd <= gd)
                r = mid;
            else
                l = mid + 1;
        }
        mp[id].fr = l + 1;
        ans.push_back({id, t.fr, t.loc, t.lr, gd});
    }

    sort(ans.begin(), ans.end());

    cout << SZ(ans) << '\n';
    for (auto &[id, fr, loc, lr, gd] : ans)
    {
        cout << id << " " << fr << " " << loc << " " << lr << '\n';
    }

    return 0;
}