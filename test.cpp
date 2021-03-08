#include<bits/stdc++.h>
using namespace std;
#define ll                          long long
#define ull                         unsigned long long
#define ld                          long double
#define db                          double
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define MP                          make_pair
#define PB                          emplace_back
#define SZ(X)                       ((int)(X).size())   
#define mset(s, _)                  memset(s, _, sizeof(s))
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl                        "\n"
#define forn(i, l, r)                for (int i = l; i <= r; i++)
typedef pair<int, int>               pii;
typedef pair<ll, ll>                 pll;
const int INF = 0x3f3f3f3f;

namespace q_pow_mm{
    ll mm(ll a, ll b, ll m){
        ll res = 0;
        while(b){
            if(b & 1) 
                res = (res + a) % m;
            a = (a * 2) % m;
            b >>= 1;
        }
        return res;
    }
    ll q (ll a, ll b){
        ll ret = 1;
        while(b){
            if(b & 1)
                ret = ret * a;
            a = a * a;
            b = b >> 1;
        }
        return ret;
    }
    ll qm (ll a, ll b, ll c){
        a = a % c;
        ll ret = 1 % c;
        while(b){
            if(b & 1)
                ret = mm(ret, a, c) % c;
            a = mm(a, a, c) % c;
            b = b >> 1;
        }
        return ret;
    }
}
using namespace q_pow_mm;

ll get_zhishu(ll x){
	for(int i=2;i<=x;i++){
		if(x%i==0) return i;
	}
}

void solve(){
    ll n=1001733993063167141;
	ll d=212353;
	ll C=20190324;
	ll p=get_zhishu(n);
	printf("p的值为%lld\n",p);
	ll q=n/p;
	printf("q的值为%lld\n",q);
	
	ll k=(p-1)*(q-1);
    ll e = qm(d, k - 2, k);
    cout << qm(C, e, n);

}
int main()
{
    IOS;
    solve();
    return 0;
}