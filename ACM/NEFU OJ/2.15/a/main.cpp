#include <bits/stdc++.h>
using namespace std;
set<int>s;
set<int>::iterator it;
int b[1000000];
int dao(int x){
    int a[10],len=0,s=0;
    memset(a,0,sizeof(a));
    while(x)
    {
        a[++len]=x%10;
        x=x/10;
    }
    for(int i=1;i<=len;i++)
    {
        s=(s+a[i])*10;
    }
    return s/10;
}
int main()
{
    int n,x,y;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            if(x%10==0)
                b[x]++;
            y=dao(x);
            s.insert(y);
        }
    for(it=s.begin();it!=s.end();it++){
        if(it!= s.begin())
            printf(" ");
        for(int i=*it;i<=1e9;i=i*10){
            if(b[i])
            {printf("%d",i); break;}
        }
        printf("%d",dao(*it));
    }
    printf("\n");
    s.clear();
}
    return 0;
}
