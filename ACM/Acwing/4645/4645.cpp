/*
 * @Author: NEFU AB-IN
 * @Date: 2023-01-02 19:41:09
 * @FilePath: \Acwing\4645\4645.cpp
 * @LastEditTime: 2023-01-02 20:47:41
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
// const int N = 1e5 + 10;

// #undef int

const int N = 200010, M = 18;

int n, m, k;
int w[N], f[N][M], Log[N]; // 用来求log的
unordered_map<int, int> pre;

void init()
{
    for (int j = 0; j < M; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            if (!j)
                f[i][j] = w[i];
            else
                f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
    }
    Log[1] = 0;
    for (int i = 2; i <= n; i++)
        Log[i] = Log[i / 2] + 1;
}

int query(int l, int r)
{
    int k = Log[r - l + 1];
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

signed main()
{
    IOS;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        w[i] = pre[x ^ k];
        pre[x] = i; // 记录x自己的最右位置
    }
    init();
    for (int i = 1; i <= n; ++i)
        cout << w[i] << " ";
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        if (query(l, r) >= l)
            puts("yes");
        else
            puts("no");
    }

    return 0;
}