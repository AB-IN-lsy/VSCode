#include <bits/stdc++.h>
using namespace std;
map<char,int>vis;
set<int>s;
set<int>::iterator it1;
const int N=1e2+1;
int prime[N];
int b[N];
int cnt=1,max1=1e2;

int init(){
    memset(b,1,sizeof(b));
    b[0]=b[1]=0;
    for(int i=2;i<=max1;i++){
        if(b[i]){
            prime[cnt++]=i;
            for(int j=1;j<=cnt&&prime[j]*i<=max1;j++){
                b[prime[j]*i]=0;
                if(i%prime[j]==0)
                    break;
            }
        }
    }
    return 0;
}

int main()
{
    string str;
    init();
    while(cin>>str){
        s.clear();
        vis.clear();
        for(int i=0;i<str.size();i++)
        {
            vis[str[i]]++;
        }
        for(int i=0;i<str.size();i++)
        {
            s.insert(vis[str[i]]);
        }
        it1=s.begin();
        int num=(*s.rbegin())-(*it1);
        if(b[num])
            cout<<"Lucky Word"<<endl<<num<<endl<<endl;
        else
            cout<<"No Answer"<<endl<<num<<endl<<endl;

    }
    return 0;
}
