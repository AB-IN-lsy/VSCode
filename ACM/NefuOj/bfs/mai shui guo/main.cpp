#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int sum,a[1001],ans,flag;
int m,n,k;
int main()
{
    //20 5 3
    //1 2 3 15 6
    scanf("%d%d%d",&m,&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<(1<<n);i++){
        sum=0;
        ans=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))
            {sum+=a[j];ans++;}
        }
        if(sum==m&&ans==k)
        {flag=1;break;}
    }
    if(flag==1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
