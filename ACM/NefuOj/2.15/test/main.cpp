#include <bits/stdc++.h>
using namespace std;
set<int>s;
set<int>::iterator it;
int dao(int x){
    int a[9],len=0,s=0;
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
            y=dao(x);
            s.insert(y);
        }
    for(it=s.begin();it!=s.end();it++){
        cout<<*it<<endl;
    }
}
    return 0;
}
