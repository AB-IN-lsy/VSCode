#include <bits/stdc++.h>
using namespace std;
int num[51][51];
char str[51][51];
int x2[4]={1,-1,0,0};
int y2[4]={0,0,1,-1};
struct sa
{
    int x;
    int y;
};
queue<sa>q;
int main()
{
    int w,h,x,y;
    while(cin>>h>>w){
    if(h==0&&w==0)
    break;
    memset(str,0,sizeof(str));
    memset(num,0,sizeof(num));
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            cin>>str[i][j];
        }
    }
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            if(str[i][j]=='#')
                num[i][j]=1;
            if(str[i][j]=='@')
            {x=i;y=j;}
        }
    }
    num[x][y]=1;
    q.push({x,y});
    int ans=0;
    while(!q.empty()){
        sa tmp;
        tmp=q.front();
        ans++;
        q.pop();
        int x1=tmp.x;
        int y1=tmp.y;
        for(int i=0;i<4;i++){
            int x3=x1+x2[i];
            int y3=y1+y2[i];
            if(x3>=1&&x3<=w&&y3>=1&&y3<=h&&num[x3][y3]==0)
            {q.push({x3,y3});num[x3][y3]=1;}
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}
