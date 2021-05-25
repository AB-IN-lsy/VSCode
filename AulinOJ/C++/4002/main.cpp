#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn=1e6+10;
inline ll read() { ll s = 0, w = 1; char ch = getchar(); while (ch < 48 || ch > 57) { if (ch == '-') w = -1; ch = getchar(); }    while (ch >= 48 && ch <= 57) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar(); return s * w; }
inline void write(ll x) { if (!x) { putchar('0'); return; } char F[200]; ll tmp = x > 0 ? x : -x; if (x < 0)putchar('-'); int cnt = 0;    while (tmp > 0) { F[cnt++] = tmp % 10 + '0';     tmp /= 10; }    while (cnt > 0)putchar(F[--cnt]); }
ll n,d,m,a[maxn],ans;
int main()
{
    n=read();d=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=1;i<=n;i++){
        if(a[i]<=a[i-1]){
            m=((a[i-1]-a[i])/d)+1;
            a[i]+=m*d;
            ans+=m;
        }
    }
    write(ans);
}
