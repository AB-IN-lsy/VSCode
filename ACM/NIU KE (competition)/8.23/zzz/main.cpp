#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e7+10;
ll n,m,k,a[N],b[N],c[N],c1[N];
int main()
{
    cin>>n>>m>>k;
    //n=read();m=read();k=read();
    for(int i=1;i<=n;i++) cin>>a[i];//a[i]=read();
    for(int i=n;i>=1;i--) b[i]=a[i]+b[i+1];
    for(int i=1;i<=m;i++) cin>>c[i];//c[i]=read();
    sort(c+1,c+1+n,greater<int>());
    for(int i=1;i<=m;i++) c1[i]=c[i]+c1[i-1];
    int id=upper_bound(b+1,b+1+n,c[1],greater<int>())-b;
    if(id<=n){
        ll ans=b[1]-b[id]+c1[k];

        cout<<ans<<endl;
        //write(ans);
    }
    else cout<<b[1]<<endl;
        //write(b[1]);
	return 0;
}
/*
5 4 3
100 99 30 2 1
10 9 8 3
*/
