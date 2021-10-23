/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-31 12:55:17
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-05 23:25:01
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const int N = 1e6 + 10;
int a[N], q1[N], q2[N];
int n, m, x;

int main()
{
    IOS;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    while(m --){
        cin >> x;
        int l1 = 1, r1 = 0; // 单调递减队列，维护最大值，队首元素对应的值即最大值，l1队首下标
        int l2 = 1, r2 = 0; // 单调递增队列，维护最小值，队首元素对应的值即最小值，l2队首下标
        int l = 1;
        LL ans = 0;
        for(int i = 1; i <= n; i ++){
            while(l1 <= r1 && a[q1[r1]] <= a[i]) r1 --; // 从后往前弹
            while(l2 <= r2 && a[q2[r2]] >= a[i]) r2 --; // 从后往前弹
            q1[++ r1] = i;
            q2[++ r2] = i;
            while(l <= i && a[q1[l1]] - a[q2[l2]] > x){
                ans += 1LL * (n - i + 1);
                l ++; // 移动左端点
                while(l1 <= r1 && q1[l1] < l) l1 ++; // 保证队首不滑出l
                while(l2 <= r2 && q2[l2] < l) l2 ++;
            }
        }	
        cout << ans << '\n';
    }
    return 0;
}