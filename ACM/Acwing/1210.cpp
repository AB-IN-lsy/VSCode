/*
 * @Author: NEFU AB-IN
 * @Date: 2022-03-24 15:38:38
 * @FilePath: \ACM\Acwing\1210.cpp
 * @LastEditTime: 2022-03-24 15:38:52
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;

int n;
int maxsum[N][30];
int minsum[N][30];
int Log[N]; // 用来求log的
int a[N];

void log_init() // 求log的函数
{
    Log[1] = 0;
    for (int i = 2; i <= n; i++)
        Log[i] = Log[i / 2] + 1;
}

void rmq_init()
{
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            maxsum[i][j] = max(maxsum[i][j - 1], maxsum[i + (1 << (j - 1))][j - 1]);
            minsum[i][j] = min(minsum[i][j - 1], minsum[i + (1 << (j - 1))][j - 1]);
        }
}
int query(int l, int r)
{
    int k = Log[r - l + 1];
    int Max = max(maxsum[l][k], maxsum[r - (1 << k) + 1][k]);
    int Min = min(minsum[l][k], minsum[r - (1 << k) + 1][k]);
    return Max - Min;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxsum[i][0] = minsum[i][0] = a[i];
    }
    log_init();
    rmq_init();
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (query(i, j) == j - i)
                ans += (1LL);
        }
    }
    cout << ans << '\n';
    return 0;
}