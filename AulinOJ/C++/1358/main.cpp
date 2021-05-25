#include<bits/stdc++.h>
using namespace std;
bool judge[30];
int n,r;
int main(){
    while(cin>>n>>r){
    int ans=0;
    memset(judge,0,sizeof(judge));
    for(int i=r+1;i<=n;i++)
        judge[i]=true;
    do{
        ans++;
    }while(next_permutation(judge+1,judge+n+1));
    cout<<ans<<endl;
    }
    return 0;
}
