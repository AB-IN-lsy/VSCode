#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,j,x,y;
    int a[1000],b[1000],c[1000];
    scanf ("%d%d",&x,&y);
    for (i=1; i<=x; i++)
        scanf("%d",&a[i]);
    for (i=1; i<=y; i++)
        scanf("%d",&b[i]);
    int minn=0x3f3f3f3f;
    for (i=1;i<=x;i++)
        for (j=1;j<=y;j++)
        minn=min(minn,abs(a[i]-b[j]));
    printf("%d",minn);
    return 0;
}
