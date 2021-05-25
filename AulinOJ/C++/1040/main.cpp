//第一种方法：划边界
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int x2[9] = {0,-2, -1, 1, 2, 2, 1, -1, -2};
const int y2[9] = {0,1, 2, 2, 1, -1, -2, -2, -1};
ll xb,yb,mx,my;
ll data[30][30];
bool judge[30][30];
int main()
{
    cin>>xb>>yb>>mx>>my;
    for(int i=0;i<9;i++){
        ll x3=mx+x2[i];
        ll y3=my+y2[i];
        if(x3>=0&&x3<=xb&&y3>=0&&y3<=yb)
        judge[x3][y3]=true;
    }
    for(ll i=0;i<=xb;i++){
        if(!judge[i][0])
            data[i][0]=1;
        else
            break;//由于边界只有一条路，这时候边界走不了了，就要跳出循环
    }
    for(ll i=0;i<=yb;i++){
        if(!judge[0][i])
            data[0][i]=1;
        else
            break;
    }
    for(ll i=1;i<=xb;i++){
        for(ll j=1;j<=yb;j++){
            if(judge[i][j])
                data[i][j]=0;
            else
               data[i][j]=data[i-1][j]+data[i][j-1];
        }
    }
    cout<<data[xb][yb]<<endl;
    return 0;
}
/*第二种方法：放一个点，然后状态转移方程
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int bx,by,mx,my;
ull f[30][30];
bool s[30][30];
int main(){
    scanf("%d%d%d%d", &bx, &by, &mx, &my);
    bx+=2; by+=2; mx+=2; my+=2;
    f[2][2] =1;
    for(int i = 0; i <9; i++)
        s[ mx + fx[i] ][ my + fy[i] ] = 1;
    for(int i = 2; i <= bx; i++){
        for(int j = 2; j <= by; j++){
            if(s[i][j])continue;
            f[i][j] = max( f[i][j] , f[i - 1][j] + f[i][j - 1] ); //这句比较重要
        }
    }
    printf("%llu\n", f[bx][by]);
    return 0;
}
*/
