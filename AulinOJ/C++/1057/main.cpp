#include <bits/stdc++.h>
using namespace std;
int i,money,cost,ans;
int main()
{
    for(i=1;i<=12;i++){
        money=money+300;
        cin>>cost;
        money=money-cost;
        if(money<0){
            cout<<"-"<<i;
            break;
        }
        ans=ans+money/100;
        money=money%100;
    }
    if(i==13){
        money=money+ans*120;
        cout<<money;
    }
    return 0;
}
