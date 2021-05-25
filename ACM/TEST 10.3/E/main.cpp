#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n, m, a[N],l,r;
bool check(int mid) {
    int cnt=1,now=1;;
    for(int i=2;i<=n;i++){
        if(a[i]-a[now]>=mid){
            cnt++;
            now=i;
        }
    }
    return cnt>=m;
}
int main() {

    while (~scanf("%d%d", &n, &m) && n!=0 && m!=0) {
        int mx=-1;
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
            mx=max(a[i],mx);
        }
        sort(a+1,a+1+n);
        l=1;r=mx;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)) l=mid+1;
            else r=mid-1;
        }
        printf("%d\n", r);
    }
    return 0;
}
