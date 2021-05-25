#include <bits/stdc++.h>

using namespace std;
int n,ans,cnt;
int main()
{
    freopen("w.txt","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=1) printf("%d,%d : ans=%d\n",i,j,ans);
            for(int k=1;k<=n;k++){
                int tmp=__gcd(k,__gcd(i,j));
                ans+=tmp;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
