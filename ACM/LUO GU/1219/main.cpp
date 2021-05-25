#include <bits/stdc++.h>
using namespace std;
bool l[10001],d1[10001],d2[10001];
int sum,n,a[10001];
void dfs(int i)
{
    if(i>n){
        sum++;
        if(sum>3)
            return;
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int j=1;j<=n;j++){
        if((!l[j])&&(!d1[i+j])&&(!d2[i-j+n])){
            a[i]=j;
            l[j]=true;
            d1[i+j]=true;
            d2[i-j+n]=true;
            dfs(i+1);
            l[j]=false;
            d1[i+j]=false;
            d2[i-j+n]=false;
        }
    }
}
int main()
{
    cin>>n;
    dfs(1);
    cout<<sum;
    return 0;
}
