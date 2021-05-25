#include <bits/stdc++.h>
using namespace std;
int t,x,y,z,ans;
double tmp;
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    for(int k=1;k<=t;k++){
        cin>>x>>y>>z;
        if(z<=x) printf("Case #%d: 1\n",k);
        else if(x<=y) printf("Case #%d: QAQ\n",k);
        else{
            tmp=(z-x)*pow((x-y),-1);
            ans=ceil(tmp)+1;
            printf("Case #%d: %d\n",k,ans);
        }
    }
    return 0;
}
