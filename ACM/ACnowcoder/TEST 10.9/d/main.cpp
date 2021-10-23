#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
double a[N],b[N],c[N],sum,d[N],ans;
int k,e,t,n;
int main()
{
    cin>>t;
    while(t--){
        ans=0.0;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++) cin>>c[i];
        for(int i=0;i<n;i++){
            d[i]=1-(1-a[i])*(1-b[i])*(1-c[i]);
        }
        cin>>e;
        for(int i=0;i<(1<<n);i++)
        {
            sum=1.0;
            k=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j)){
                    sum*=d[j];
                    k++;
                }
                else sum*=(1-d[j]);
            }
            if(k==e) ans+=sum;
        }
        printf("%.4f\n",ans);
    }
    return 0;
}
