#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int a[N];
int t;

void solve()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    if(count(a + 1, a + 1 + n, a[1]) == n){
        puts("No");
        return;
    }
    else{
        puts("Yes");
        int las = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] != a[1]){
                printf("1 %d\n", i);
                las = i;
            }
        }
        for(int i = 2; i <= n; i++){
            if(a[i] == a[1]){
                printf("%d %d\n", i, las);
            }
        }
    }
}

int main()
{
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
