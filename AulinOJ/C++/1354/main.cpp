#include <iostream>
using namespace std;
int n,dp[10001];
int main()
{
    dp[1]=2;dp[2]=4;dp[3]=7;dp[4]=13;
    while(cin>>n){
        for(int i=5;i<=n;i++){
            dp[i]=2*dp[i-1]-dp[i-4];
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
