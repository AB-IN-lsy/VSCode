#include <bits/stdc++.h>
using namespace std;
int a[2000010],n,t,s;
int main()
{
    scanf("%d",&t);
    while(t--){
       scanf("%d%d",&n,&s);
       int ans=0x3f3f3f3f;
       memset(a,0,sizeof(a));
       for(int i=1;i<=n;i++)
           scanf("%d",&a[i]);
       int i=1,j=1;
       int sum=a[1];
       while(i<=j&&j<=n){
           if(sum>=s){
               ans=min(ans,j-i+1);
               sum-=a[i];
               i++;
           }
           else{
               j++;
               sum+=a[j];
           }
       }
       if(ans==0x3f3f3f3f) ans=0;
       printf("%d\n",ans);
    }
    return 0;
}
