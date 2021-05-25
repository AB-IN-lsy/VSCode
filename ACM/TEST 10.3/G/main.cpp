#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e6+10;
int v, n, f[12], dp[N], pre[N], a[N];
int main() {
    while (~scanf("%d%d", &v, &n)) {
        memset(dp, 0x3f, sizeof(dp));
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++)
            scanf("%d", &f[i]);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = f[i]; j <= v; j++) {
                if (dp[j - f[i]] < inf && dp[j - f[i]] + 1 < dp[j]) {
                    dp[j] = dp[j - f[i]] + 1;
                    pre[j] = j - f[i];
                }
            }
        }
        if (dp[v] == inf)
            puts("-1");
        else {
            while (v) {
                a[v - pre[v]]++;
                v = pre[v];
            }
            for(int i=1;i<=n;i++){
                printf("%d ",a[f[i]]);
            }
            printf("\n");
        }
    }
    return 0;
}
/*
2000 7 10 20 50 100 200 500 1000
250 4 10 20 125 150
35 4 10 20 125 150
48 4 1 8 16 20
40 4 1 10 13 37
43 5 1 2 21 40 80
*/
