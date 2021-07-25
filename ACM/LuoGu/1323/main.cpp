#include <bits/stdc++.h>
using namespace std;
priority_queue<int , vector<int> ,greater<int> >vis;
string ans,ans2;
int k,m;
string sum(int a){
    stringstream ss;
    ss << a;
    string ans = ss.str();
    return ans;
}
int main(){
    cin>>k>>m;
    vis.push(1);
    int cnt=0;
    while(cnt<k){
        int tmp1=2*vis.top()+1;
        int tmp2=4*vis.top()+5;
        ans+=(sum(vis.top()));
        vis.pop();
        vis.push(tmp1);
        vis.push(tmp2);
        cnt++;
    }
    cout<<ans<<endl;
    int l=0,r=m,maxn=0;
    while(l<=r&&r<ans.length()){//贪心
        for(int i=l;i<=r;i++){
            if(ans[i]-'0'>maxn){
                maxn=ans[i]-'0';
                l=i+1;//相当于删数了
            }
        }
            ans2+=(sum(maxn));
            r++;
            maxn=0;
    }
    cout<<ans2;
    return 0;
}
