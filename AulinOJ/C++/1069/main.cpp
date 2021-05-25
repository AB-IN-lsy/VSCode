#include <bits/stdc++.h>
using namespace std;
set<int>s;
set<int>::iterator it;
int main()
{
   int n;
   int x;
   while(cin>>n){
    for(int i=1;i<=n;i++){
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
    for(it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
   }
    return 0;
}
