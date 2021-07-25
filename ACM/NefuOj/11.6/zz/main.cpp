#include <bits/stdc++.h>

using namespace std;

const int N = 1e7+10;
int a[N];

void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) a[i] = i;
    for(int i = 2; k >= 1; i++){
        if(i % 2){
            a[i] = a[i - 1] - (k --);
        }
        else{
            a[i] = a[i - 1] + (k --);
        }
    }
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
}

int main()
{
    solve();
    return 0;
}
