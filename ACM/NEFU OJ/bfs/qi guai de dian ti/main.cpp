#include <bits/stdc++.h>
using namespace std;
struct sa
{
    int x;
    int step;
};
queue<sa>q;
bool a[1010];
int b[1010];
int N,A,B,x3;
void bfs(int x)
{//3 3 1 2 5
    q.push({x,0});
    a[x]=false;
    sa tmp;
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        x3=tmp.x;
        if(x3==B)
        {
            break;
        }
            int x4=x3+b[x3];
            if(x4>=1&&x4<=N&&a[x4]==true)
            {
                q.push({x4,tmp.step+1});
                a[x4]=false;
            }
            int x5=x3-b[x3];
            if(x5>=1&&x5<=N&&a[x5]==true)
            {
                q.push({x5,tmp.step+1});
                a[x5]=false;
            }
    }
    if(x3==B)
        {printf("%d\n",tmp.step);return;}
    else
        printf("-1\n");
}
int main()
{
    scanf("%d%d%d",&N,&A,&B);
    for(int i=1;i<=N;i++){
        scanf("%d",&b[i]);
    }
    memset(a,true,sizeof(a));
    bfs(A);
    return 0;
}
