#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int x2[9] = {0,-2, -1, 1, 2, 2, 1, -1, -2};
const int y2[9] = {0,1, 2, 2, 1, -1, -2, -2, -1};
ll xb,yb,mx,my;
ll data[40][40];
bool judge[40][40];
int main()
{
    while(cin>>xb>>yb>>mx>>my){
    xb+=2; yb+=2; mx+=2; my+=2;
    memset(data,0,sizeof(data));
    memset(judge,false,sizeof(judge));
    for(int i=0;i<9;i++){
        ll x3=mx+x2[i];
        ll y3=my+y2[i];
        if(x3>=2&&x3<=xb&&y3>=2&&y3<=yb)
        judge[x3][y3]=true;
    }
    for(ll i=2;i<=xb;i++){
        if(!judge[i][2])
            data[i][2]=1;
        else
            break;
    }
    for(ll i=2;i<=yb;i++){
        if(!judge[2][i])
            data[2][i]=1;
        else
            break;
    }
    for(ll i=3;i<=xb;i++){
        for(ll j=3;j<=yb;j++){
            if(judge[i][j])
                data[i][j]=0;
            else
               data[i][j]=data[i-1][j]+data[i][j-1];
        }
    }
    cout<<data[xb][yb]<<endl;
}
    return 0;
}
