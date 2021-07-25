#include <bits/stdc++.h>
using namespace std;
int vis[130];//ASCIIÂë×Ü¹²127¸ö
string a;
int main()
{
    ios::sync_with_stdio(false);
    cin>>a;
    int n=a.size();
    int i=0,j=0;
    int sum=1,ans=0x3f3f3f3f;
    vis[a[0]]++;
    while(i<=j&&j<n){
        if(sum>=26){
            ans=min(ans,j-i+1);
            vis[a[i]]--;
            if(vis[a[i]]==0) sum--;
            i++;
        }
        else{
            j++;
            vis[a[j]]++;
            if(vis[a[j]]==1) sum++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
