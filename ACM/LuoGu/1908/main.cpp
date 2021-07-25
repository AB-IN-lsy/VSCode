#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)
#pragma GCC optimize(3)
const ll maxn=1e6+10;
ll n,cnt,a[maxn],b[maxn];
char buf[1 << 21], *p1=buf, *p2=buf;
inline ll getc(){
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll read() {
    ll ret = 0,f = 0;char ch = getc();
    while (!isdigit (ch)) {
        if (ch == '-') f = 1;
        ch = getc();
    }
    while (isdigit (ch)) {
        ret = ret * 10 + ch - 48;
        ch = getc();
    }
    return f ? -ret : ret;
}
inline void write(ll x) { if (!x) { putchar('0'); return; } char F[200]; ll tmp = x > 0 ? x : -x; if (x < 0)putchar('-'); int cnt = 0;    while (tmp > 0) { F[cnt++] = tmp % 10 + '0';     tmp /= 10; }    while (cnt > 0)putchar(F[--cnt]); }
void _merge(ll l,ll mid,ll r)
{
    ll p1=l,p2=mid+1;
    for(ll i=l;i<=r;i++){
        if((p1<=mid) && ((p2>r) || a[p1] <= a[p2])){
            b[i]=a[p1];
            p1++;
        }
        else{
            b[i]=a[p2];
            p2++;
            cnt+=mid-p1+1;
        }
    }
    for(ll i=l;i<=r;i++) a[i]=b[i];
}
void erfen(ll l,ll r)
{
    ll mid=(l+r)/2;
    if(l<r){
        erfen(l,mid);
        erfen(mid+1,r);
    }
    _merge(l,mid,r);
}
int main()
{
    n=read();
    for(ll i=1;i<=n;i++)
        a[i]=read();
    erfen(1,n);
    write(cnt);putchar(10);
    return 0;
}
