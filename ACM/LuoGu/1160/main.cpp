#include <bits/stdc++.h>
using namespace std;
vector<int>vis;
vector<int>::iterator it;
int num,p,ans;
bool a[1000000];//用布尔判断节约时间，太管用了，用来判断是否删除了
int main()
{
    int n;
    scanf("%d",&n);
    vis.push_back(1);
    for(int i=1;i<=n-1;i++){
        scanf("%d%d",&num,&p);
        if(p)
            vis.insert(find(vis.begin(),vis.end(),num)+1,i+1);//右插
        else
            vis.insert(find(vis.begin(),vis.end(),num),i+1);//左插
    }
    int n1;
    scanf("%d",&n1);
    for(int i=1;i<=n1;i++){
        scanf("%d",&ans);
        a[ans]=true;
    }
    for(it=vis.begin();it!=vis.end();it++){
        if(!a[*it])
        printf("%d ",*it);
    }
    return 0;
}
