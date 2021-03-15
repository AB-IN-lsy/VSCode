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

void solve(){
	int A, B, a, b;
	cin >> A >> B >> a >> b;
	int suma = 0, sumb = 0, cnta = 0, cntb = 0;
	while(A - suma >= a){
		cnta += 1;
		suma += (a + a - 1);
	}
	while(B - sumb >= b){
		cntb += 1;
		sumb += (b + b - 1);
	}
	cout << cnta * cntb << endl;
}

int main()
{
	IOS;
	solve();
	return 0;
}