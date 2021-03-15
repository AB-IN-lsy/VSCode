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

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	c *= 2;
    d *= 2;
	int l = a % c >= c / 2 ? a / c + 1: a / c;
	int r = b % d >= d / 2 ? b / d + 1: b / d;
	cout << l * r << endl;
	return 0;
}