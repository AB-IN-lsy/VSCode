#include <iostream>
using namespace std;
int b1[10001],b2[10001],a[10001];
int n,k,s,l,r,cnt;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    r=n;
    for(int i=n;i>=1;i--){
        s+=a[i];
        if(s>k){
            s=a[i];
            l=i+1;
            b1[++cnt]=l;
            b2[cnt]=r;
            r=i;
        }
    }
    l=1;
    b1[++cnt]=l;
    b2[cnt]=r;
    for(int i=cnt;i>=1;i--)
        cout<<b1[i]<<" "<<b2[i]<<endl;
    return 0;
}
