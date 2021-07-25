#include <bits/stdc++.h>
using namespace std;
const int maxn=110;
int x2[8]={1,1,1,0,0,-1,-1,-1};
int y2[8]={1,0,-1,1,-1,0,1,-1};
const string str="yizhong";
bool judge[maxn][maxn];
char a[maxn][maxn];
int n;
void dfs(int x,int y)
{
    for(int i=0;i<8;i++){
        for(int j=1;j<=6;j++){
            int x3=x+j*x2[i];
            int y3=y+j*y2[i];
            if(x3<1||x3>n||y3<1||y3>n||a[x3][y3]!=str[j])
               goto label;
        }
        for(int j=1;j<=6;j++){
            judge[x][y]=true;
            int x3=x+j*x2[i];
            int y3=y+j*y2[i];
            judge[x3][y3]=true;
        }
        label:;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]=='y')
                dfs(i,j);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(judge[i][j]==false)
                a[i][j]='*';
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
