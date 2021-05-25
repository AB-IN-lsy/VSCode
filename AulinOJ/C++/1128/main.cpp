#include <bits/stdc++.h>
using namespace std;
stack<int>s;
int a,b,sum;
char str;
const int m=10000;
int main()
{
    cin>>a;
    a%=m;
    s.push(a);
    while(cin>>str>>b){
        if(str=='*'){
            int tmp=s.top();
            s.pop();
            s.push(tmp*b%m);
        }
        else
            s.push(b);
    }
    while(!s.empty()){
        sum+=s.top();
        sum%=m;
        s.pop();
    }
    cout<<sum<<endl;
    return 0;
}
