#include <bits/stdc++.h>
using namespace std;
int a[1001],n,m;
int main()
{
    while(cin>>n>>m){
        for(int i=1;i<=n;i++)
            a[i]=2*i;
        int cnt=0,n1=n;
        while(n>0){
            int sum=0,ans=0;
            for(int i=1;i<=m;i++){
                if(cnt+i>n1)
                    break;
                sum+=a[cnt+i];
                ans++;
            }
            cout<<sum/ans<<" ";
            n-=m;
            cnt+=ans;
        }
        cout<<endl;
    }
    return 0;
}
