#include <bits/stdc++.h>
#pragma GCC diagnostic error "-std=c++11"
using namespace std;
typedef long long ll;
map< pair<ll,ll>,int >vis;
map< pair<ll,ll>,int >::iterator it;//Ҳ���Բ�����map����������һ��ȥ�����ڵ�16��itǰ�Ӹ�auto
int main()
{
    ll n,x,y,ans=0,num;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        vis[{x,y}]++;
    }

    for(it=vis.begin();it!=vis.end();it++){
        x=it->first.first;//����map��һ����Ա�ĵ�һ��
        y=it->first.second;
        if(x==0&&y==0)
            num=vis[{x,y}];
        else
            num=vis[{x,y}]+vis[{-x,-y}];
        if(num%2==0)
        {
            ans+=num;
            vis[{x,y}]=0;
            vis[{-x,-y}]=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
