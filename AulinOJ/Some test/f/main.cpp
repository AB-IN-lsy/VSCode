#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
typedef long long ll;
using namespace std;
set<ll>s,a;//s为模版集合,a为不含x的集合(即s的逆操作)
set<ll>::iterator it;
const ll maxn=1e6+10;
inline ll read() { ll s = 0, w = 1; char ch = getchar(); while (ch < 48 || ch > 57) { if (ch == '-') w = -1; ch = getchar(); }    while (ch >= 48 && ch <= 57) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar(); return s * w; }
inline void write(ll x) { if (!x) { putchar('0'); return; } char F[200]; ll tmp = x > 0 ? x : -x; if (x < 0)putchar('-'); int cnt = 0;    while (tmp > 0) { F[cnt++] = tmp % 10 + '0';     tmp /= 10; }    while (cnt > 0)putchar(F[--cnt]); }
ll n,op,x;
int main()
{
    n=read();
    while(n--){
        op=read();x=read();
        if(op==1){
            s.insert(x);
            a.insert(x+1);
            a.erase(x);
        }
        if(op==2){
            s.erase(x);
            a.insert(x);
        }
        if(op==3){
            ll ans=s.count(x)==0?x:*a.lower_bound(x);
            write(ans);
            putchar(10);
        }
    }
    return 0;
}
