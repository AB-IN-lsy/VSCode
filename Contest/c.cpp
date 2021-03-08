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
#define ls                          i << 1
#define rs                          i << 1 | 1
typedef pair<int, int>               pii;
typedef pair<ll, ll>                 pll;
const int INF = 0x3f3f3f3f;

ll sum(ll n) {
    if(n<=1) return n;
    ll ans=0;
    for(ll l=1,r;l<=n;l=r+1) {
        r=n/(n/l);
        ans+=(n/l)*(l+r)*(r-l+1)/2;
    }
    return ans;
}

int main()
{
    IOS;
    ll n;
    cin >> n;
    cout << sum(sum(n)) << endl;
    return 0;
}