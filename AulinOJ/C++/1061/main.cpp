#include <bits/stdc++.h>
using namespace std;
const int minn=1e2+10;
int a[minn];
int main()
{
    int high;
    for(int i=1;i<=10;i++){
        cin>>high;
        a[i]=high;
    }
    int h;
    cin>>h;
    int ans=0;
    for(int i=1;i<=10;i++){
        if(a[i]<=(h+30))
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
