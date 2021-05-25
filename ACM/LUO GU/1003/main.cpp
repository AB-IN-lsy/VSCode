#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a[N][5],n,x,y;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
        a[i][3]=a[i][3]+a[i][1];//ÏòÓÒ
        a[i][4]=a[i][4]+a[i][2];//ÏòÉÏ
    }
    cin>>x>>y;
    for(int i=n;i>=1;i--){
        if(x>=a[i][1]&&x<=a[i][3]&&y>=a[i][2]&&y<=a[i][4]){
            cout<<i;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}
