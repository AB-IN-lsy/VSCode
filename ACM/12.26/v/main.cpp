#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;
LL n, Mod, p, q, a1, a2, ans;
struct mat{
	LL m[4][4];
}Ans, base;
inline void init() {
	Ans.m[1][1] = a2, Ans.m[1][2] = a1;
	base.m[1][1] = p, base.m[2][1] = q, base.m[1][2] = 1;
}
inline mat mul(mat a, mat b) {
	mat res;
	memset(res.m, 0, sizeof(res.m));
	for(int i=1; i<=2; i++) {
		for(int j=1; j<=2; j++) {
			for(int k=1; k<=2; k++) {
				res.m[i][j] += (a.m[i][k] % Mod) * (b.m[k][j] % Mod);
				res.m[i][j] %= Mod;
			}
		}
	}
	return res;
}
inline void Qmat_pow(int p) {
	while (p) {
		if(p & 1) Ans = mul(Ans, base);
		base = mul(base, base);
		p >>= 1;
	}
}
LL m;
int main() {
	scanf("%lld%lld%lld%lld%", &p, &q, &n, &m);
	Mod = 1e9 + 7;
	a1 = 1;
	a2 = 1;
	if(n == 1) {
		cout<<a1;
		return 0;
	}
	if(n == 2) {
		cout<<a2;
		return 0;
	}
	init();
	Qmat_pow(n-2);
	ans = Ans.m[1][1];
	ans %= Mod;
	printf("%lld", ans);
}
