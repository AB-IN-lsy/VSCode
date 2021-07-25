#include <bits/stdc++.h>
using namespace std;
int f[101];
int a,b,n;
int main()
{
    f[1]=f[2]=1;
    while(cin>>a>>b>>n){
        if(a==0&&b==0&&n==0) break;
        if(n==1||n==2)
            cout<<"1"<<endl;
        else{
                int i;
        for(i=3;i<=50;i++){
              f[i]=(a*f[i-1]+b*f[i-2])%7;
              if(f[i]==1&&f[i-1]==1) break;
    }
    n=n%(i-2);
    if(n==0)
        cout<<f[i-2]<<endl;
    else
        cout<<f[n]<<endl;}
    }
    return 0;
}
