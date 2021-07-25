#include <bits/stdc++.h>
using namespace std;
struct sa
{
    string str;
    int x;
}a[11];
int t,num;
int main()
{
    cin>>t;
    while(t--){
        num++;
        int ans=0;
        for(int i=1;i<=10;i++){
            cin>>a[i].str>>a[i].x;
            ans=max(ans,a[i].x);
        }
        cout<<"Case #"<<num<<":"<<endl;
        for(int i=1;i<=10;i++){
            if(a[i].x==ans)
                cout<<a[i].str<<endl;
        }
    }
    return 0;
}
