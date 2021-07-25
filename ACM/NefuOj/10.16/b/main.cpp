#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int co[maxn], n;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> co[i];
	sort(co+1, co+1+n);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(co[n-i+1] >= i-1)	ans = i;
		else
			break;
	cout << ans << endl;
}
