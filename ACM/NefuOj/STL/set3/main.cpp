#include <bits/stdc++.h>
using namespace std;
set<string>s;
set<string>::iterator it;
int main()
{
    ios::sync_with_stdio(false);
    int n,judge;
    string word;
    while(cin>>n){
        int ans=0,cnt;
            s.clear();
        for(int i=1;i<=n;i++){
            cin>>judge>>word;
            if(judge==0)
            s.insert(word);
            if(judge==1){
                ans=0;
                cnt=s.size();
             for(it=s.begin();it!=s.end();it++){
                 if(word==*it)
                {cout<<"YES"<<endl;break;}
                ans++;
            }
            if(ans==cnt)
            cout<<"NO"<<endl;//����дif(*it==word),��Ȼ��RE
        }
    }

}
    return 0;
}
