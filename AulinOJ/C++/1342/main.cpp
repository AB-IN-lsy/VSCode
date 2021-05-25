#include <bits/stdc++.h>
using namespace std;
int n,m,x;
set<int>s;
set<int>::iterator it;
int main()
{
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++)
        {cin>>x;s.insert(x);}
        s.insert(m);
        for(it=s.begin();it!=s.end();it++)
            cout<<*it<<" ";
        cout<<endl;
        s.clear();
    }
    return 0;
}
