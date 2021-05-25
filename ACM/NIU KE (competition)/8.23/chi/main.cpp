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
       int sum=0;
       while(i<=j&&j<=n){
           sum+=a[j];
           while(sum>=s){
               ans=min(ans,j-i+1);
               sum-=a[i];
               i++;
           }
           j++;
       }
       if(ans==0x3f3f3f3f) ans=0;
       printf("%d\n",ans);
    }
    /*
    2
    10 15
    5 1 3 5 10 7 4 9 2 8
    5 11
    1 2 3 4 5
    */
    return 0;
}
