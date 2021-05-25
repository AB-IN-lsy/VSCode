#include <bits/stdc++.h>
using namespace std;
int minn=1e5;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int i,j;
        int flag=0;
        int a[minn]={0};
        for(j=0;j<n;j++)
        {
            cin>>a[j];
        }
        for(i=0;i<(1<<n);i++)
        {
           int sum=1;
           for(j=0;j<n;j++)
         {
             if(i&(1<<j))
                sum*=a[j];
         }
           if(sum==m)
           {
               cout<<"yes"<<endl;
               flag=1;
               break;
           }
        }

        if(flag==0)
        {
            cout<<"no"<<endl;
        }

    }
    return 0;
}
