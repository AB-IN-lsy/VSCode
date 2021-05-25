/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-05-10 19:25:00
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-05-10 19:31:45
 */
#include<bits/stdc++.h>
using namespace std;
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct cmp { //自定义vector排序
    bool operator() (const pair<int,vector<int> >&a, const pair<int,vector<int> >&b) const{
        if(a.first != b.first)
            return a.first > b.first;
        else return a.second < b.second;
    }
};

map < vector<int> , int > cnt;
vector < pair<int, vector<int> > > ans;

int main()
{
	IOS;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		vector <int> line(m);
		for(auto& i : line) cin >> i;
		cnt[line] ++;
	}
	for(auto& p : cnt) {
		ans.push_back({p.second, p.first});
	}
	sort(ans.begin(), ans.end(), cmp());

	cout << SZ(cnt) << endl;
	for(auto& p : ans){
		cout << p.first;
		for(auto i : p.second) cout << " " << i;
		cout << endl;
	}
	return 0;
}

