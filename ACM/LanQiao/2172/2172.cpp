/*
 * @Author: NEFU AB-IN
 * @Date: 2023-05-24 12:55:42
 * @FilePath: \LanQiao\2172\2172.cpp
 * @LastEditTime: 2023-05-24 12:55:55
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

const int N = 200010, M = 18;

int n, m;
int w[N], f[N][M], Log[N]; // 用来求log的

void init()
{
    for (int j = 0; j < M; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            if (!j)
                f[i][j] = w[i];
            else
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
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

    return 0;
}