#include <bits/stdc++.h>
using namespace std;
const int ans=1000;
int n;
int a[25][25],dp[25],list1[25];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
        dp[i]=ans;
    }
    dp[n]=0;
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            if((a[i][j]>0)&&(dp[j]!=ans)&&(dp[i]>a[i][j]+dp[j])){
                dp[i]=a[i][j]+dp[j];
                list1[i]=j;
            }
        }
    }
    int num=1;
    cout<<"minlong="<<dp[1]<<endl;
    while(num>0)
    {
        if(list1[num]>0)
            cout<<num<<" ";
        else
            cout<<num;
        num=list1[num];
    }
    return 0;
}
