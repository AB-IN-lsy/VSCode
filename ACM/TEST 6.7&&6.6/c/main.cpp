#include <bits/stdc++.h>
typedef unsigned long long ll;
const ll maxn=1e6;
using namespace std;
inline ll read() { ll s = 0, w = 1; char ch = getchar(); while (ch < 48 || ch > 57) { if (ch == '-') w = -1; ch = getchar(); }    while (ch >= 48 && ch <= 57) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar(); return s * w; }
inline void write(ll x) { if (!x) { putchar('0'); return; } char F[200]; ll tmp = x > 0 ? x : -x; if (x < 0)putchar('-'); int cnt = 0;    while (tmp > 0) { F[cnt++] = tmp % 10 + '0';     tmp /= 10; }    while (cnt > 0)putchar(F[--cnt]); }
ll x,y,t,nx,ny;
int main()
{
    t=read();
    while(t--){
        ll ans=0;
        x=read();y=read();
        if(x==y){
            write(x*4);putchar('\n');
            continue;
        }
        else{
            while(1){
            nx=min(x,y);
            ny=max(x,y);
            ny-=nx;
            ans+=nx*4;
            x=nx;
            y=ny;
            if(nx==ny)
            {ans+=nx*4;break;}
            }
        }
        write(ans);putchar('\n');
    }
}
