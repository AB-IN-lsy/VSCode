#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500001;
int a[maxn],n;
map<ll,int>vis;
int main()
{
    ios::sync_with_stdio(false);
    for(int i=1;i<=500000;i++){
        if(a[i-1]-i>0&&vis[a[i-1]-i]==0)
            a[i]=a[i-1]-i;
        else
            a[i]=a[i-1]+i;
        vis[a[i]]=1;
    }
    while(cin>>n&&n!=-1){
        cout<<a[n]<<endl;
    }
    return 0;
}
