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

const int N = 1e6 + 10;

struct sa{
	int ts;
	int id;
}a[N];

bool b[N];
int ans[N];
bool cmp(const sa a, const sa b){
	return a.ts < b.ts;
}

void solve(){
	int n, m, t, ts, id;
	cin >> n >> m >> t;
	forn(i, 1, m) cin >> a[i].ts >> a[i].id;
	sort(a + 1, a + 1 + m, cmp);
	forn(i, 1, m){
		if(!b[a[i].ts]) {
			b[a[i].ts] = 1;
		}
		ans[a[i].id] += 2;
	}
}

int main()
{
	IOS;
	solve();
	return 0;
}