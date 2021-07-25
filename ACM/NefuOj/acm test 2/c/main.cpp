#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int n,k,a[1000001];
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF){
        int l=1,r=n,mid=0,cnt=0;
        while(l<=r){
            cnt++;
            mid=(l+r)/2;
            if(mid==k)
                break;
            else if(mid<k)
                l=mid+1;
            else
                r=mid-1;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
