#include <bits/stdc++.h>
using namespace std;
char str[50][50];
int x2[4]={-1,1,0,0};
int y2[4]={0,0,-1,1};
void dfs(int x,int y)
{
    str[x][y]='*';
    for(int i=0;i<4;i++){
        int x3=x+x2[i];
        int y3=y+y2[i];
        if(x3>=1&&x3<=4&&y3>=1&&y3<=4&&str[x3][y3]=='#')
            dfs(x3,y3);
    }
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++){
                cin>>str[i][j];
            }
        }
        dfs(1,1);
        if(str[4][4]=='*')
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
