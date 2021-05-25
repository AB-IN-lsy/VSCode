#include<bits/stdc++.h>
using namespace std;
int n,a[101],all,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        all+=a[i];
    }
    all/=n;
    for(int i=1;i<=n;i++){
        if(a[i]-all){
          a[i+1]+=a[i]-all;
          ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
