#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
const ll maxn=1e3+10;
ll f[maxn],a,t,cnt;
void init(){
    f[1]=1;
    f[2]=1;
    for(int i=3;i<=93;i++){
        f[i]=f[i-1]+f[i-2];
    }
}
int main()
{
    init();
    for(int i=1;i<=93;i++){
        cout<<f[i]<<endl;
    }
    return 0;
}
