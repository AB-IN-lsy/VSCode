#include <bits/stdc++.h>
using namespace std;
vector<int>a[10010];
int n,m,x,y;
int main()
{
    while(~scanf("%d%d",&n,&m)){
        while(m--){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
         if(a[i].size()==0)
              printf("\n");
        for(int j=0;j<a[i].size();j++){
            if(j==a[i].size()-1)
                printf("%d\n",a[i][j]);
            else
                printf("%d ",a[i][j]);
        }
        a[i].clear();
    }
}

    return 0;
}
