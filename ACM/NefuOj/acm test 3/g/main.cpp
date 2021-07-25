#include <bits/stdc++.h>
using namespace std;
struct sa
{
    int l;
    int r;
}a[5010];
int t,n;
int cmp(const sa &a,const sa &b)
{
    if(a.l!=b.l)  return a.l<b.l;
    else return a.r<b.r;
}
bool judge[5001];
int main()
{
    cin>>t;
    while(t--){
        int cnt=0;
        memset(judge,false,sizeof(judge));
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i].l>>a[i].r;
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            int k=i;
            if(!judge[i])
            {judge[i]=true;cnt++;}
            for(int j=i+1;j<=n;j++){
                if((!judge[j])&&(a[j].l>=a[k].l)&&(a[j].r>=a[k].r)){
                    judge[j]=true;
                    k=j;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
