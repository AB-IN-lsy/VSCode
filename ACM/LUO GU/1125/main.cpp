#include <bits/stdc++.h>
using namespace std;
set<int>s;
set<int>::iterator it1;
set<int>::reverse_iterator it;
const int N=1e4+5;
int  cnt,sum,ans,prime[N],pre[N],vis[130];
bool flag[N];
void init()
{
    memset(flag,1,sizeof(flag));
    flag[1]=cnt=0;
    for(int i=2;i<=N;i++)
    {
        if(flag[i])
        {
            prime[++cnt]=i;
            pre[i]=cnt;
        }
        for(int j=1;j<=cnt&&prime[j]*i<=N;j++)
        {
            flag[prime[j]*i]=0;
            if(i%prime[j]==0)break;
        }
    }
}
int main()
{
    string str;
    init();
    cin>>str;
    for(int i=0;i<str.size();i++){
        vis[str[i]]++;
    }
    for(int i=0;i<str.size();i++){
        s.insert(vis[str[i]]);
    }
    it1=s.begin();
    it=s.rbegin();
    int num=(*s.rbegin())-(*it1);
    if(pre[num])
        cout<<"Lucky Word"<<endl<<num<<endl<<endl;
    else
        cout<<"No Answer"<<endl<<"0"<<endl<<endl;
    return 0;
}
