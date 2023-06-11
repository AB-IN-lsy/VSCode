/*
 * @Author: NEFU AB-IN
 * @Date: 2023-06-09 18:08:14
 * @FilePath: \LanQiao\2940\2940.cpp
 * @LastEditTime: 2023-06-09 18:08:20
 */
#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5, M = 18;

int n, w[N];
int f[N][M];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void init()
{
    for (int j = 0; j < M; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            if (!j)
                f[i][j] = w[i];
            else
                f[i][j] = gcd(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
}

int query(int l, int r)
{
    int len = r - l + 1;
    int k = log(len) / log(2);
    return gcd(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    init();

    int pre = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = pre + 1, r = i;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (query(mid, i) >= i - mid + 1)
                r = mid;
            else
                l = mid + 1;
        }
        if (query(l, i) == i - l + 1)
        {
            ans++;
            pre = i;
        }
    }
    cout << ans;

    return 0;
}