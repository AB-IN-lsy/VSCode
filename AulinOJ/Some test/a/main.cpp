#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
typedef long long ll;
using namespace std;
const ll maxn=1e6+10;
inline ll read() { ll s = 0, w = 1; char ch = getchar(); while (ch < 48 || ch > 57) { if (ch == '-') w = -1; ch = getchar(); }    while (ch >= 48 && ch <= 57) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar(); return s * w; }
inline void write(ll x) { if (!x) { putchar('0'); return; } char F[200]; ll tmp = x > 0 ? x : -x; if (x < 0)putchar('-'); int cnt = 0;    while (tmp > 0) { F[cnt++] = tmp % 10 + '0';     tmp /= 10; }    while (cnt > 0)putchar(F[--cnt]); }
ll n,id,y,a[15][15];
int main()
{
    n=read();
    while(n--){
        id=read();y=read();
        int x=1;
        if(id==1){
            while(!a[x][y]&&!a[x-1][y]&&!a[x][y+1]&&!a[x-1][y+1]&&x<=10)
                x++;
            x--;
            a[x][y]=a[x][y+1]=a[x-1][y]=a[x-1][y+1]=1;
        }
        if(id==2){
            while(!a[x][y]&&!a[x-1][y]&&!a[x][y+1]&&!a[x][y+2]&&x<=10)
                x++;
            x--;
            a[x][y]=a[x-1][y]=a[x][y+1]=a[x][y+2]=1;
        }
        if(id==3){
            while(!a[x][y]&&!a[x][y+1]&&!a[x][y+2]&&!a[x][y+3]&&x<=10)
                x++;
            x--;
            a[x][y]=a[x][y+1]=a[x][y+2]=a[x][y+3]=1;
        }
        if(id==4){
            while(!a[x][y]&&!a[x][y+1]&&!a[x-1][y+1]&&!a[x][y+2]&&x<=10)
                x++;
            x--;
            a[x][y]=a[x][y+1]=a[x-1][y+1]=a[x][y+2]=1;
        }
    }
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            write(a[i][j]),putchar(32);
        }
        putchar(10);
    }
    return 0;
}
