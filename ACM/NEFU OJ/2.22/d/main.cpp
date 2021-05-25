#include <bits/stdc++.h>
using namespace std;
map<int,int>c;
map<int,int>d;
set<int>a;
set<int>::iterator it;
int n,m,x,cnt;
int main()
{
    scanf("%d%d",&n,&m);
    a.clear();
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        a.insert(x);
        c[x]++;
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        a.insert(x);
        d[x]++;
    }
    for(it=a.begin();it!=a.end();it++){
            if(c[*it]!=0&&d[*it]==0)
                {printf("%d\n",*it);cnt++;}
    }
    a.clear();
    if(cnt==0){
        printf("So crazy!!!");
    }
    return 0;
}
