#include <bits/stdc++.h>
using namespace std;
set<int>s;
int main()
{
    int n,num,x;
    while(cin>>n>>num){
        s.clear();
        for(int i=1;i<=n;i++){
            cin>>x;
            s.insert(x);
        }
        set<int>::iterator it;
        int ans=0,cnt=s.size();
        for(it=s.begin();it!=s.end();it++){
            if(cnt<num)
                {cout<<"NO RESULT"<<endl;break;}
            ans++;
            if(ans==num)
                {cout<<*it<<endl;break;}
        }

    }
    return 0;
}
