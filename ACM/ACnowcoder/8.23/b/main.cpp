#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
int n,m;
struct sa{
    int num;
    int step;
    string s;
};
int a[30];
queue<sa>q;
unordered_map<string,int>vis;
int main()
{
    cin>>n;
    for(int i=1;i<=n-1;i++) cin>>a[i];
    cin>>m;
    q.push((sa) {a[1]+a[2],2,"+"});
    q.push((sa) {a[1]-a[2],2,"-"});
    int ans=0;
    while(!q.empty()){
        sa tmp=q.front();
        q.pop();
        if(tmp.step==n-1&&tmp.num==m){
            vis[tmp.s]++;
            ans++;
            continue;
        }
        if(tmp.step==n-1) continue;
        q.push( (sa) {tmp.num+a[tmp.step+1],tmp.step+1,tmp.s+"+"});
        q.push( (sa) {tmp.num-a[tmp.step+1],tmp.step+1,tmp.s+"-"});
    }
    cout<<ans<<endl;
    for(auto it=vis.begin();it!=vis.end();it++){
        cout<< it->first <<endl;
    }
    return 0;
}
