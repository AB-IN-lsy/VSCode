#include<bits/stdc++.h>
int main(){
	long long n;
	std :: cin >> n;
	n & 1 ? std :: cout << n - 1 : std :: cout << n + 1;
}