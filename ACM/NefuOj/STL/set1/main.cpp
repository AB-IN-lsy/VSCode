#include <bits/stdc++.h>
using namespace std;
set<int>s;
int main()
{
    int n,x;
    while(cin>>n){
        s.clear();
        for(int i=1;i<=n;i++){
            cin>>x;
            s.insert(x);
        }
        cout<<s.size()<<endl;
        set<int>::iterator it;
        for(it=s.begin();it!=s.end();it++){
            if(it!=s.begin())
                cout<<" ";
            cout<<*it;
        }
        cout<<endl;
    }
    return 0;
}
