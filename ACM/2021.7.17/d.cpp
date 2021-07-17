/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2020-12-10 10:46:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-17 12:27:10
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;


int main()
{
    int n, m, x, cnt = 0;
    LL ans = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            scanf("%1d", &x);
            if(x == 0) cnt ++;
            if(x == 1 || j == n){
                if(cnt >= m){
                    ans += cnt - m + 1;
                }
                cnt = 0;
            }
        }
    }
    for(int i = 1; i <= m; i ++) scanf("%1d", &x);;
    printf("%lld\n", ans);
    return 0;
}