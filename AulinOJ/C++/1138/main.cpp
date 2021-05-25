#include <bits/stdc++.h>
using namespace std;
int a[6][6],b[210],c[210];
int n,na,nb,jia,yi,x;
int main()
{
    memset(a,2,sizeof(a));
    //甲是行，乙是列
    a[0][1]=0;a[0][2]=1;a[1][2]=0;a[0][3]=1;a[1][3]=1;a[2][3]=0;a[0][4]=0;a[1][4]=0;a[2][4]=1;a[3][4]=1;
    a[1][0]=1;a[2][0]=0;a[2][1]=1;a[3][0]=0;a[3][1]=0;a[3][2]=1;a[4][0]=1;a[4][1]=1;a[4][2]=0;a[4][3]=0;
    cin>>n>>na>>nb;
    for(int i=0;i<na;i++){
        cin>>b[i];
    }
    for(int i=0;i<nb;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        if(a[b[i%na]][c[i%nb]]==0)
            yi++;
        if(a[b[i%na]][c[i%nb]]==1)
            jia++;
    }
    cout<<jia<<" "<<yi<<endl;
    return 0;
}
