/*
 * @Author: NEFU AB-IN
 * @Date: 2022-09-03 17:46:21
 * @FilePath: \GPLT\A1014\A1014.cpp
 * @LastEditTime: 2022-09-03 21:36:14
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
    int n, m, k, q, x;
    cin >> n >> m >> k >> q;

    queue<PII> g[N], p; // g表示窗口, p代表候补处
    vector<int> time(N), ans(k + 10);
    // time 每个窗口累计时间
    // ans 结果
    int id = 0;
    while (true)
    {
        if (!k)
            break;
        if (SZ(g[0]) >= m)
        {
            while (k--)
            {
                cin >> x;
                p.push({++id, x});
            }
            break;
        }
        for (int j = 0; j < n; ++j)
        {
            if (k)
            {
                cin >> x;
                g[j].push({++id, x}); // 编号，时间
                k--;
            }
        }
    }
    for (int i = 1; i <= 1000; ++i)
    { // 枚举分钟
        for (int j = 0; j < n; ++j)
        { // 枚举窗口
            if (SZ(g[j]))
            {
                auto tp = g[j].front();
                int id = tp.first, t = tp.second;
                if (i == t + time[j])
                {
                    g[j].pop();
                    ans[id] = i;
                    time[j] += t;

                    if (i >= 540)
                    {
                        while (SZ(g[j]))
                        {
                            auto tp = g[j].front();
                            ans[tp.first] = -1; // 超时了
                            g[j].pop();
                        }
                    }

                    if (i < 540 && SZ(p))
                    {
                        g[j].push(p.front());
                        p.pop();
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    { // 处理窗口剩余情况
        while (SZ(g[i]))
        {
            auto tp = g[i].front();
            ans[tp.first] = -1; // 超时了
            g[i].pop();
        }
    }

    while (SZ(p))
    {
        auto tp = p.front();
        ans[tp.first] = -1; // 超时了
        p.pop();
    }

    while (q--)
    {
        int x;
        cin >> x;
        int t = ans[x];
        if (t == -1)
        {
            printf("Sorry\n");
            continue;
        }

        int h = t / 60, m = t % 60;
        printf("%02lld:%02lld\n", 8 + h, m);
    }

    return 0;
}