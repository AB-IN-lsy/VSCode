#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn=5e6+10;
inline ll read() { ll s = 0, w = 1; char ch = getchar(); while (ch < 48 || ch > 57) { if (ch == '-') w = -1; ch = getchar(); }    while (ch >= 48 && ch <= 57) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar(); return s * w; }
inline void write(ll x) { if (!x) { putchar('0'); return; } char F[200]; ll tmp = x > 0 ? x : -x; if (x < 0)putchar('-'); int cnt = 0;    while (tmp > 0) { F[cnt++] = tmp % 10 + '0';     tmp /= 10; }    while (cnt > 0)putchar(F[--cnt]); }
ll quickmod (ll a, ll b ,ll c)
{
    ll ret=1%c;
    while(b){
        if(b&1)
            ret=ret*a%c;
        a=a*a%c;
        b=b>>1;
    }
    return ret%c;
}
ll a,b,c;
int main()
{
    a=read();b=read();c=read();
    printf("%lld^%lld mod %lld=%lld",a,b,c,quickmod(a,b,c));
    return 0;
}
