#include <bits/stdc++.h>

using namespace std;


int n, m;
long long x;
void solve()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%lld", &x);
            if((i + j) & 1){
                if(!(x & 1)) x += 1;
            }
            else{
                if(x & 1) x += 1;
            }
            printf("%lld ", x);
        }
        printf("\n");
    }
}

int t;

int main()
{
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
