#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
int n,len;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    len = 1;
    b[1] = a[1];
    for(int i = 2; i <= n; i++){
        if(a[i] > b[len]) b[++len] = a[i];
        else{
            int id = lower_bound(b + 1, b + 1 + len, a[i]) - b;
            b[id] = a[i];
        }
    }
    cout<< len <<endl;
    return 0;
}
