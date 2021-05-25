#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x;
int main()
{
    while(cin>>n){
        x=n%3;
        if(x==1||x==2){
            cout<<"no\n";
        }
        else{
            cout<<"yes\n";
        }
    }
    return 0;
}
