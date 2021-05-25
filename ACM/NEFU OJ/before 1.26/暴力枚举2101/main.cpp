#include <bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        int flag=0;
        for(int i=0;i<=n;i+=4)
        {
            if((n-i)%7==0)
            {
                int y=(n-i)/7;
                ans1=i/4;
                ans2=y;
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("xinganheixiong\n");
        else
        {
            for(int i=1;i<=ans1;i++)
                printf("4");
            for(int i=1;i<=ans2;i++)
                printf("7");
            printf("\n");
        }
    }
    return 0;
}
