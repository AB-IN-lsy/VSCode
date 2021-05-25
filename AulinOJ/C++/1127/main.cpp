#include <bits/stdc++.h>
using namespace std;

int counter (int x,int y)
{
    int num=log10(x)+1;
    int ans=0,x1;
    for(int i=1;i<=num;i++)
    {
        x1=x%10;
        if(x1==y)
            ans++;
        x=x/10;
    }
    return ans;
}

int main()
{
    int x,y,ans=0;
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        ans+=counter(i,y);
    }
    cout<<ans<<endl;
    return 0;
}
