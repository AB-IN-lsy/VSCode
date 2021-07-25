#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int a[35];
void solve(int i)
{
    int n , m, ans = 0;
    scanf("%d%d", &n, &m);
    int tmp = lower_bound(a, a+32, n) - a;
    if(n == a[tmp]) tmp++;
    if(m >= tmp) v.push_back(i);
    else v.push_back(i-1);
}


int t,ans;
int main()
{
    scanf("%d", &t);
    a[0] = 1;
    for(int i = 1; i <=32; i++){
        a[i] = a[i-1] * 2;
    }
    for(int i = 1; i <= t; i++){
        solve(i);
    }
    ans = v[0];
    for(int i = 1; i < v.size();i++){
        ans ^= v[i];
    }
    printf("%d\n", ans);
    return 0;
}
