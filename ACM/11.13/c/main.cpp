#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6+10;
ll a[N];
int n;
void solve(int j)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    ll tmp = a[n];
    for(int i = n; i > 1; i--){
        double p = ceil( (double) tmp / 2);
        tmp = ceil( p ) + a[i - 1];
    }
    printf("Case #%d: %lld\n", j, tmp);
}

int t;

int main()
{
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}
