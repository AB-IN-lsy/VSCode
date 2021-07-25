#include<bits/stdc++.h>
using namespace std;
int m,n,z,c;
int main()
{
    cin>>m>>n;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            for(int k=i+1;k<=m;k++){
                for(int l=j+1;l<=n;l++)
                  if(k-i==l-j)
                    z++;
                  else
                    c++;
            }
        }
    }
    cout<<z<<" "<<c;
}
