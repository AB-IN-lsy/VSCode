/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2020-12-10 10:46:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-05-09 16:21:07
 */
#include<bits/stdc++.h>
using namespace std;
#define ll                          long long
#define SZ(X)                       ((int)(X).size())
#define MP                          make_pair
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector <int> ans, t;
vector < vector<int> > v;
int st[10010];
int mx;

void dfs(int x, int sum){
	if(sum > mx) ans = t, mx = sum;
	else if(sum == mx && t < ans) ans = t; 
	for(auto& i : v[x]){
		t.push_back(i);
		dfs(i, sum + 1);
		t.pop_back();
	}
	return;
}

int main()
{
	IOS;
	int n;
	cin >> n;
	v.resize(n);
	for(auto& vi : v){
		int tmp;
		cin >> tmp;
		vector < int > vv(tmp);
		for(auto& i : vv) cin >> i, st[i] = 1;
		vi = vv;
	}
	int root = 0;
	while(st[root]) root ++;
	dfs(root, 1);
	cout << mx << endl;
	cout << root;
	for(int j = 0; j < SZ(ans); j++){
		cout << " "<< ans[j];
	}
	return 0;
}