#include<bits/stdc++.h>
using namespace std;
set<int>s;
set<int>::iterator it;
int n,x,y;
const int maxn=1e9+10;
int main()
{
    cin>>n;
    while(n--){
        cin>>x>>y;
        if(x==1){
            s.insert(y);
        }
        if(x==2){
            s.erase(y);
        }
        if(x==3){
           for(int i=y;i<=maxn;i++){
                if(s.find(i)!=s.end())
                 continue;
                cout<<i<<endl;
                break;
           }
        }
    }
}
