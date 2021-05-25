#include <bits/stdc++.h>
using namespace std;
const int minn=1e3+10;
int a[minn];
int main()
{
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int tmp=0,maxn=a[1];
        for(int l=1;l<=n;l++)
        {
            tmp=a[l];
            maxn=max(maxn,tmp);
            for(int r=l+1;r<=n;r++)
            {
               tmp+=a[r];
               maxn=max(maxn,tmp);
            }
        }
        cout<<maxn<<endl;
    }
    return 0;
}
