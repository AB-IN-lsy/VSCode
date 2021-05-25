#include <bits/stdc++.h>
using namespace std;
int n,f[1000010];
int main()
{
    while(cin>>n){
        memset(f,0,sizeof(f));
        f[0]=1;
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=0;j<=50000;j++){
                int s=f[j]*i+cnt;
                f[j]=s%10;
                cnt=s/10;
            }
        }
        int k=0;
        for(k=50000;k>=0;k--)
            if(f[k]!=0) break;
        for(int i=k;i>=0;i--)
            cout<<f[i];
        cout<<endl;
    }
    return 0;
}
