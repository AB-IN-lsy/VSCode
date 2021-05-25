#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
const int N=1e6+10;
struct sa
{
    string s;
    int f;
    int id;
}a[N];
int n,m,k;
char x;
int cmp(const struct sa a , const struct sa b)
{
    if(a.f!=b.f) return a.f>b.f;
    else return a.id<b.id;
}
int main()
{
    IOS;
    //freopen("data10.in","r",stdin);
    //freopen("w.txt","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].f;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=m;i++){
        cin>>x>>k;
        int flag=0,cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j].s[a[j].s.size()-1]==x){
                cnt+=1;
                if(cnt==k){
                    cout<<a[j].s<<endl;
                    flag=1;
                    break;
                }
            }
        }
        if(!flag) cout<<"Orz YYR tql"<<endl;
    }
    return 0;
}
