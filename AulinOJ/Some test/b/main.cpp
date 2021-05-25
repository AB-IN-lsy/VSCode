#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,num,x;
const int maxn=2e5+10;
int a[maxn],b[maxn];
char judge;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    while(scanf("%c",&judge)!=EOF){
    if(judge=='c')
    {
        scanf("%d%d%d",&l,&r,&num);
        for(int i=l;i<=r;i++)
            a[i]+=num;
    }
    if(judge=='q')
    {
        scanf("%d",&x);
        int cnt=-1;
        for(int i=x;i<=n;i++){
            int minn=0x3f3f3f3f;
            for(int j=x;j<=i;j++)
                minn=min(minn,a[j]);
            if(a[i]==minn)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    }
}
