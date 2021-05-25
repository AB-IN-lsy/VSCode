#include <bits/stdc++.h>
using namespace std;
int a,b,t;
int main()
{
    cin>>t;
    while(t--){
        cin>>a>>b;
        int ans_a=0,ans_b=0;
        for(int i=1;i<=a/2;i++){
            if(a%i==0)
                ans_a+=i;
        }
        for(int i=1;i<=b/2;i++){
            if(b%i==0)
                ans_b+=i;
        }
        if(ans_a==b&&ans_b==a)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
