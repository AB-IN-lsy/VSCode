#include <bits/stdc++.h>
using namespace std;
int n=0;//定义与归0
int main(){
    while(cin>>n){
    int s=0;
    for(;n!=0;n/=10)
        s=s*10+n%10;//同上一种的套路，暴力直接循环搞
    cout<<s<<endl;
    }
    return 0;//输出,0会没掉的
