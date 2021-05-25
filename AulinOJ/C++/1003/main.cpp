#include <bits/stdc++.h>
using namespace std;
bool judge(int x){
int a=0,b=0;
while(x>0)
{
    if(x%2)
     a++;
    else
     b++;
    x=x/2;
}
return a>b;
}
int main()
{
    int a=0,b=0;
    for(int i=1;i<=1000;i++){
        if(judge(i))
            a++;
        else
            b++;
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}
