/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2020-12-10 10:46:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-05-10 20:40:59
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define MP                          make_pair
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct cmp{
	bool operator() (const int &a, const int &b){
		return a > b;
	}
};
int main()
{
	IOS;
	int a[5] = {1, 8, 3, 9, 1};
	priority_queue <int, vector<int>, cmp> q(a, a + 5);
	cout << q.top() << " "; q.pop();
	cout << q.top() << " "; q.pop();
	cout << q.top() << " "; q.pop();
	cout << q.top() << " "; q.pop();
	cout << q.top() << " "; q.pop();
	return 0;
}