/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-30 03:42:22
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-05 09:51:56
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const int N = 1e5 + 10;
int arr[N];
double sum[N];
int n, m, x, y;

bool check(double avg, int l, int r) // 共l个数，长度必须大于等于r
{
    for (int i = 1; i <= l; ++i)
        sum[i] = sum[i - 1] + arr[i] - avg; //上图中的bi, 即维护了一个前缀最小值
    double minv = 0;
    for (int i = r; i <= l; ++i) // 从r之后枚举, 因为长度必须大于r 
    {
        minv = min(minv, sum[i - r]); // 从sum[0]开始，找最小前缀和，这样后面的前缀和
        if (sum[i] >= minv) // 只要大于前面的最小前缀和就可以，满足贪心策略
            return true;
    }
    return false;
}

int main()
{
    IOS;
    cin >> n >> m >> x >> y;
    double l = 0, r = 0;

    for (int i = 1; i <= n; ++i){
        scanf("%d", arr + i);
        r = max(r, double(arr[i]));
    }
    while (r - l > 1e-7){
        double mid = (l + r) / 2;
        if (check(mid, n, x))
            l = mid; // n个数，长度要为x
        else
            r = mid;
    }
    double ans = 0;
    ans += r;
//////////////////////////////////
    l = r = 0;
    for (int i = 1; i <= m; ++i){
        scanf("%d", arr + i);
        r = max(r, double(arr[i]));
    }
    while (r - l > 1e-7){
        double mid = (l + r) / 2;
        if (check(mid, m, y))
            l = mid;
        else
            r = mid;
    }
    ans += r;
    printf("%.7f\n", ans);
    return 0;
}
