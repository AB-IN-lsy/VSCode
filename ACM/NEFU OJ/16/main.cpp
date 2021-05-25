#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[21][21][21];
ll dg(int x,int y,int z)
{
    if(x<=0||y<=0||z<=0)
        return 1;
    if(x>20||y>20||z>20)
        return dg(20,20,20);
    if(x<y&&y<z){
        if(dp[x][y][z]==-1)
            dp[x][y][z]=dg(x,y,z-1)+dg(x,y-1,z-1)-dg(x,y-1,z);
        return dp[x][y][z];
    }
    else{
        if(dp[x][y][z]==-1)
            dp[x][y][z]=dg(x-1,y,z)+dg(x-1,y-1,z)+dg(x-1,y,z-1)-dg(x-1,y-1,z-1);
        return dp[x][y][z];
    }
}
int x,y,z;
int main()
{
    while(cin>>x>>y>>z){
        if(x==-1&&y==-1&&z==-1) break;
        memset(dp,-1,sizeof(dp));
        printf("w(%d, %d, %d) = %d\n",x,y,z,dg(x,y,z));
    }
    return 0;
}
