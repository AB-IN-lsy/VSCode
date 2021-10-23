/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-09 12:43:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-09 12:59:56
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll pairOr,pairSum;
	cin>>pairOr>>pairSum;
	if(pairOr>pairSum) cout<<"Impossible"<<endl;
	ll pairAnd=pairSum-pairOr;
	if((pairOr&pairAnd)==pairAnd) cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
}
