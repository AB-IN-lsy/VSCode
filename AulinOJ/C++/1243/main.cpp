#include <bits/stdc++.h>
using namespace std;
string a;
int ans,c,cnt,b;
int main()
{
    cin>>a;
    b=a.size();
    for(int i=0;i<b;i++){
        ans+=pow(a[i]-'0',3);
        cnt+=(a[i]-'0')*pow(10,a.size()-i);
    }
    if(ans==cnt/10)
        cout<<"1";
    else
        cout<<"0";
    return 0;
}
