#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin>>n;
    while(n!=1){
      if(n%2==0){
        cout<<n;
        cout<<"/2="<<n/2<<endl;
        n=n/2;
      }
      else{
        cout<<n;
        cout<<"*3+1="<<n*3+1<<endl;
        n=n*3+1;
      }
    }

    return 0;
}
