#include <bits/stdc++.h>
using namespace std;
struct sa
{
    int xh;
    int yw;
    int sx;
    int yy;
    int sum;
}a[1001];
int cmp(const sa &a,const sa &b)
{
    if(a.sum!=b.sum) return a.sum>b.sum;
    else if(a.yw!=b.yw) return a.yw>b.yw;
    else return a.xh<b.xh;
}
int n;
int main()
{
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>a[i].yw>>a[i].sx>>a[i].yy;
            a[i].xh=i;
            a[i].sum=a[i].yw+a[i].sx+a[i].yy;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=5;i++){
            cout<<a[i].xh<<" "<<a[i].sum<<endl;
        }
        cin>>n;
        if(n==8){
                cout<<endl;
            memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>a[i].yw>>a[i].sx>>a[i].yy;
            a[i].xh=i;
            a[i].sum=a[i].yw+a[i].sx+a[i].yy;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=5;i++){
            cout<<a[i].xh<<" "<<a[i].sum<<endl;
        }
        }
    return 0;
}
