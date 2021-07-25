#include <bits/stdc++.h>
using namespace std;
struct sa
{
    int start;
    int endn;
}a[1001];
int cmp(const sa &a,const sa &b)
{
    return a.endn<b.endn;
}
int n;
int main()
{
    while(cin>>n){
        if(n==0)
            break;
    for(int i=1;i<=n;i++){
        cin>>a[i].start>>a[i].endn;
    }
    sort(a+1,a+n+1,cmp);
    int sum=1;
    sa tmp=a[1];
    for(int i=2;i<=n;i++){
        if(tmp.endn<=a[i].start){
            sum++;
            tmp=a[i];
        }
    }
    cout<<sum<<endl;
    }

    return 0;
}
