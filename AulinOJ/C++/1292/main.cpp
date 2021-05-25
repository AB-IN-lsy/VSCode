#include <bits/stdc++.h>
using namespace std;
int n,a[10001];
int cmp(int a,int b)
{
    if(a!=b) return abs(a)>abs(b);
}
int main()
{
    while(cin>>n&&n!=0){
       for(int i=1;i<=n;i++){
         cin>>a[i];
       }
       sort(a+1,a+n+1,cmp);
       for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
       }
       cout<<endl;
    }
    return 0;
}
