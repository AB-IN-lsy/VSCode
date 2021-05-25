#include <bits/stdc++.h>
using namespace std;
int a[2000010],n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        a[i]=i;
    int i=1,j=1;
    int sum=a[1];
    while(i<=j&&j<=n){
        if(sum>=n){
            if(sum==n) printf("%d %d\n",i,j);
            sum-=a[i];//左指针先减数
            i++;
        }
        else{
            j++;//右指针先自增
            sum+=a[j];
        }
    }
    return 0;
}
