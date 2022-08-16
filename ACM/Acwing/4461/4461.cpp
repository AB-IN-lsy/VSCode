/*
 * @Author: NEFU AB-IN
 * @Date: 2022-08-16 10:01:10
 * @FilePath: \Acwing\4461\4461.cpp
 * @LastEditTime: 2022-08-16 15:53:12
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

signed main()
{
    IOS;
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            cnt += i;
        for (int i = 1;; ++i)
        {
            int x1 = x * i;
            int y1 = y * i;
            if (x1 + y1 == cnt)
            {
                x = x1;
                y = y1;
                break;
            }
            if (x1 + y1 > cnt)
                break;
        }
        if (x + y != cnt)
        {
            printf("Case #%lld: IMPOSSIBLE\n", _);
            continue;
        }
        vector<int> a(N);
        auto f = [&](int &x) {
            vector<int> ans;
            for (int i = n; i > 0; --i)
            {
                if (x >= i && !a[i])
                {
                    x -= i;
                    a[i] = 1;
                    ans.push_back(i);
                }
            }
            return ans;
        };
        vector<int> ans;
        if (x >= y)
        {
            ans = f(x);
            f(y);
        }
        else
        {
            f(y);
            ans = f(x);
        }
        printf("Case #%lld: POSSIBLE\n", _);
        printf("%lld\n", SZ(ans));
        sort(ans.begin(), ans.end());
        for (auto i : ans)
        {
            printf("%lld ", i);
        }
        printf("\n");
    }
    return 0;
}