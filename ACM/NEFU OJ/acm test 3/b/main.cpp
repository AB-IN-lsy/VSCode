#include <bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
    while(cin>>a>>b){
        int cnt=0,sum=0;
        if(a==0&&b==0)
            break;
        for(int i=0;i<9;i++){
            if((a%10)+(b%10)+cnt>=10)
            {sum++;cnt=1;}
            else
            {cnt=0;}
            a/=10;b/=10;
        }
        if(sum==0)
            cout<<"No carry operation."<<endl;
        else if(sum==1)
            cout<<"1 carry operation."<<endl;
        else
            cout<<sum<<" "<<"carry operations."<<endl;
    }
    return 0;
}
