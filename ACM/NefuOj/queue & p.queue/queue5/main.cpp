#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
queue<ll>q;
set<ll>s;
set<ll>::iterator it;
int main()
{
    int a,n;
    cin>>a>>n;
    q.push(a);
    while(!q.empty()){
     ll x=q.front();
     q.pop();
     q.push(2*x+1);
     q.push(3*x+1);
     s.insert(x);//�����set��set���Զ�����
     if (s.size()==2*n)
        break;
    }
    int counter=0;
    for(it=s.begin();it!=s.end();it++){
        counter++;
        if(counter==n){
            cout<<*it<<endl;
            break;
            }

    }
    return 0;
}
