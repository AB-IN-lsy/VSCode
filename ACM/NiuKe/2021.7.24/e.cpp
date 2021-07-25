/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-24 13:47:07
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-24 16:25:32
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const LL MX = 1e18;

const int L = 1000000;
const int R = 32;

LL dp[L][R];
LL v[1004587];
LL id = 0;
int main()
{
    dp[1][0] = 1;
    for(LL i = 2; i <= L; i++){
        dp[i][0] = 0;
        dp[i][1] = i;
        for(LL j = 2; j <= R; j++){
            if((__int128)i * i * dp[i][j - 1] - dp[i][j - 2] <= 1e18) {
                dp[i][j] = i * i * dp[i][j - 1] - dp[i][j - 2];
                v[id ++] = i * i * dp[i][j - 1] - dp[i][j - 2];
            }
            else {
                dp[i][0] = j;
                break;
            }
        }
    }
    int t;
    scanf("%d", &t);
    while(t --){
        LL n;
        scanf("%lld", &n);
        if(n <= 7){
            puts("1");
            continue;
        }
        LL cnt = 1;
        sort(v, v + 1004587);
        cnt += upper_bound(v, v + 1004587, n) - v;
        printf("%lld\n", cnt);
    }
    return 0;
}
/*
1
100

1 1
2 8
2 30
3 27
4 64
*/

/*
1
1000

2 8
3 27
4 64
5 125
6 216
7 343
8 30
8 512
9 729
10 1000
27 240
30 112
112 418
*/
