#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,W;
struct sa
{
    int x;
    int y;
    double ave;
}a[101];
int cmp(const sa &a,const sa &b)
{
    if(a.ave!=b.ave) return a.ave>b.ave;
}
int main()
{
    cin>>n>>W;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].ave=a[i].y/a[i].x;
    }
    sort(a+1,a+1+n,cmp);
    int sum=0,ans=0;
    for(int i=1;i<=n;i++){
        sum+=a[i].x;
        if(sum<=W){
            ans+=a[i].y;
        }
        else{
            sum-=a[i].x;
        }
    }
    cout<<ans<<endl;
    return 0;
}
