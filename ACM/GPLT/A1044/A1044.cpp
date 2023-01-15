/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-12 22:03:33
 * @FilePath: \GPLT\A1044\A1044.cpp
 * @LastEditTime: 2023-01-12 22:23:26
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int n, m;
int a[N];

struct sa
{
    int n, l, r;
};

bool check(int l, int r)
{
    return a[r] - a[l - 1] >= m;
}

signed main()
{
    IOS;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    vector<PII> ans;
    vector<sa> tmp;
    // 枚举右端点
    for (int i = 1; i <= n; ++i)
    {
        // 二分左端点
        int l = 1, r = i;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (check(mid, i))
                l = mid;
            else
                r = mid - 1;
        }
        if (a[i] - a[l - 1] == m)
            ans.push_back({l, i});
        else
            tmp.push_back({a[i] - a[l - 1], l, i});
    }

    if (SZ(ans))
    {
        sort(ans.begin(), ans.end());
        for (auto &[l, r] : ans)
            cout << l << "-" << r << '\n';
    }
    else
    {
        sort(tmp.begin(), tmp.end(), [&](const sa a, const sa b) {
            if (a.n != b.n)
                return a.n < b.n;
            else
                return a.l < b.l;
        });
        int cnt = 0;
        for (auto &[sum, l, r] : tmp)
        {
            if (sum <= m)
                continue;
            if (!cnt)
                cnt = sum;
            if (cnt == sum)
                cout << l << "-" << r << '\n';
            else
                return 0;
        }
    }
    return 0;
}