/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-17 11:40:21
 * @FilePath: \Acwing\4510\4510.cpp
 * @LastEditTime: 2023-01-17 14:30:33
 */
// #pragma GCC optimize(1)
// #pragma GCC optimize(2)    //先开优化
// #pragma GCC optimize(3, "Ofast", "inline")
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

const int N = 1e9 + 7, INF = 0x3f3f3f3f;
int n, L, S;

struct sa
{
    int x, y, f;
};

unordered_map<long long, int> st;
vector<sa> rec;

signed main()
{
    auto fc = [&](int x, int y) { return 1LL * x * N + y; };

    scanf("%d%d%d", &n, &L, &S);
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        st[fc(x, y)] = 1;
    }
    for (int i = 0; i < S + 1; ++i)
    {
        for (int j = 0; j < S + 1; ++j)
        {
            int flag;
            scanf("%d", &flag);
            rec.push_back({S - i, j, flag}); // 更换坐标
        }
    }
    int ans = 0;
    for (auto &[t, _] : st)
    {
        auto xs = t / N, ys = t % N;
        int flag = 1;
        for (auto &[xp, yp, f] : rec)
        {
            int x = xs + xp;
            int y = ys + yp;
            if (x < 0 || x > L || y < 0 || y > L || f != (int)st.count(fc(x, y)))
            {
                flag = 0;
                break;
            }
        }
        ans += flag;
    }
    printf("%d", ans);
    return 0;
}