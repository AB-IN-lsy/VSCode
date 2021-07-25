#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int a[10001];
int t,n,l,r,x,k,ans,mx;
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>l>>r;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        mx=0;
        for(int i=l;i<=r;i++){
            for(int c=1;c<=n;c++){
                q.push(a[c]);
            }
            k=i;
            ans=0;
            while(q.size()>1){
                for(int j=1;j<=k;j++){
                    int tmp=q.top();
                    ans+=tmp;
                    q.pop();
                }
                q.push(ans);
                if(q.size()<k){
                    if(q.size()!=1)
                       ans=mx;
                    break;
                }
            }
            if(k==l)
            mx=ans;
            mx=min(mx,ans);
            q.pop();
        }
        cout<<mx<<endl;
    }
    return 0;
}
