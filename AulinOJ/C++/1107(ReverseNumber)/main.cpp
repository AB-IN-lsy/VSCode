#include <bits/stdc++.h>
using namespace std;
int n=0;//�������0
int main(){
    while(cin>>n){
    int s=0;
    for(;n!=0;n/=10)
        s=s*10+n%10;//ͬ��һ�ֵ���·������ֱ��ѭ����
    cout<<s<<endl;
    }
    return 0;//���,0��û����
