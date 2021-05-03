/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2020-12-10 10:46:04
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-04-20 19:33:50
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll nl=1e5+5;
int main(){
	ll n;
	cin>>n;
	ll i,j;
	ll m=1;
	ll num=1;
	while(1){//先让数大于n
		if(m>=n){
			break;
		}
		m=m*10+1;
		num++;
	}
	while(1){
		if(m%n==0){//能整除就结束了。
			cout<<m/n;
			break;
		}
		cout<<m/n;
		m%=n;//注意这里应该是取余，
		m=m*10+1;
		num++;
	}
	cout<<" "<<num;
}
