#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
priority_queue<ll,vector<ll>,greater<ll> >q;//此处要加空格

int main()
{
    ll n,x;
    while(cin>>n){
    for(int i=1;i<=n;i++){
        cin>>x;
        q.push(x);
    }
    while(q.size()>1){
        ll tmp1,tmp2,tmp;
        tmp1=q.top();
        q.pop();
        tmp2=q.top();
        q.pop();
        tmp=tmp1+tmp2;
        if(q.size()!=0)
            cout<<tmp<<" ";
        else
            cout<<tmp;
        q.push(tmp);
    }
    cout<<endl;
    q.pop();
}

    return 0;
}
