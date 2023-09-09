/*
 * @Author: NEFU AB-IN
 * @Date: 2023-09-07 15:45:41
 * @FilePath: \Acwing\487\487.cpp
 * @LastEditTime: 2023-09-07 15:47:51
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

const int M = 70, N = 4e4 + 10, INF = 0x3f3f3f3f;

struct sa
{
    int v, sf; // 价格 满意度
};

int dp[N];
int v[M], w[M], p[M];

vector<int> g[M];
vector<sa> W[M];

signed main()
{
    IOS;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        cin >> v[i] >> w[i] >> p[i];
        if (p[i] > 0)
        {
            g[p[i]].push_back(i);
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        if (!p[i])
        {
            int dv = v[i], dsf = v[i] * w[i];
            W[i].push_back({dv, dsf});
            switch (SZ(g[i]))
            {
            case 0: {
                break;
            }
            case 1: {
                W[i].push_back({dv + v[g[i][0]], dsf + v[g[i][0]] * w[g[i][0]]});
                break;
            }

            case 2: {
                W[i].push_back({dv + v[g[i][0]], dsf + v[g[i][0]] * w[g[i][0]]});
                W[i].push_back({dv + v[g[i][0]] + v[g[i][1]], dsf + v[g[i][0]] * w[g[i][0]] + v[g[i][1]] * w[g[i][1]]});
                W[i].push_back({dv + v[g[i][1]], dsf + v[g[i][1]] * w[g[i][1]]});
                break;
            }
            }
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        if (p[i])
            continue;
        for (int j = n; j >= 0; --j)
        {
            for (auto st : W[i])
            {
                cout << st.v << '\n';
                if (j - st.v >= 0)
                {
                    dp[j] = max(dp[j], dp[j - st.v] + st.sf);
                    cout << dp[j];
                }
            }
        }
    }

    cout << dp[n];

    return 0;
}