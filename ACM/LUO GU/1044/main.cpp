#include <bits/stdc++.h>
using namespace std;
int a[101][101],n;
int dfs(int x,int y){
    if(a[x][y])
        return a[x][y];
    if(x==0)
        return 1;
    if(y>0)
        a[x][y]+=dfs(x,y-1);
    a[x][y]+=dfs(x-1,y+1);
    return a[x][y];
}
int main()
{
    cin>>n;
    cout<<dfs(n,0)<<endl;
    return 0;
}
