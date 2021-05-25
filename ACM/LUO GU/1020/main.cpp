#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],b1[maxn],b2[maxn];
int n,len1,len2;
int main()
{
    while (cin >> a[++n]); n--;
    len1=len2=1;
    b1[1]=a[1];b2[1]=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]<=b1[len1]) b1[++len1]=a[i];
        else{
            int id=upper_bound(b1+1,b1+1+len1,a[i],greater<int>())-b1;
            b1[id]=a[i];
        }
        if(a[i]>b2[len2]) b2[++len2]=a[i];
        else{
            int id=lower_bound(b2+1,b2+1+len2,a[i])-b2;
            b2[id]=a[i];
        }
    }
    cout<<len1<<endl<<len2<<endl;
    return 0;
}
