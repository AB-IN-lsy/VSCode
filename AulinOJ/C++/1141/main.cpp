#include <bits/stdc++.h>
using namespace std;
const int minn=1e3+10;
int a[minn][minn];
int main()
{
    int n;
    while(cin>>n){
      int i=1,j=1,counter=1;
      memset(a,0,sizeof(a));
      while(counter<=n*n)
      {
          while(j<=n&& !a[i][j])
          {
              a[i][j]=counter++;
              j++;
          }//i=1,j=6
          while(i<=(n-1)&& !a[i+1][j-1])
          {
              a[i+1][j-1]=counter++;
              i++;
          }//i=5,j=6
          while(j>=3&& !a[i][j-2])
          {
              a[i][j-2]=counter++;
              j--;
          }//i=5,j=2
          while(i>=3&& !a[i-1][j-1])
          {
              a[i-1][j-1]=counter++;
              i--;
          }//i=2,j=2
      }
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
      }
    }
    return 0;
}
