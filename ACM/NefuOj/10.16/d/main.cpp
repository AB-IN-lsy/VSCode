#include <bits/stdc++.h>

using namespace std;
int x,y;
bool judge(int x)
{
    int a=0;
    while(x)
    {
        a+=x%10;
        x/=10;
    }
    int t=a%10;
    a/=10;
    while(a)
    {
        if(a%10>=t)
            return 0;
        t=a%10;
        a/=10;
    }
    return 1;
}

int main()
{

    while(cin>>x>>y){
        int ans=0;
        for(int i=x;i<=y;i++)
            if(judge(i))
                ans++;
        cout<<ans<<endl;
    }
    return 0;
}
