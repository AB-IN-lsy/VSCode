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
            s.clear();
        for(int i=1;i<=n;i++){
            cin>>judge>>word;
            if(judge==0)
            s.insert(word);
            if(judge==1){
             for(it=s.begin();it!=s.end();it++){
                 if(word==*it)
                {cout<<"YES"<<endl;break;}
            }
            if(word!=*it)
            cout<<"NO"<<endl;//不能写if(*it==word),不然会RE
        }
    }
}
    return 0;
}
