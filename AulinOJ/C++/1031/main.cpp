#include <bits/stdc++.h>
using namespace std;
set<int>s;
int main()
{
    ios::sync_with_stdio(false);
    int x,y;
    cin>>x>>y;
    for(int i=x;i<y;i++){
        for(int j=i+1;j<=y;j++){
            if(__gcd(i,j)==x&&((i*j)/__gcd(i,j)==y))
            {s.insert(i);s.insert(j);break;}
        }
    }
    cout<<s.size()<<endl;
    return 0;
}
