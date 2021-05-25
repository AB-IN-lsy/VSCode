#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,l;
    while(cin>>n)
    {
        double s=0;
        for(i=1;i<=n;i++)
        s=s+log10(i);//log10(a*b)=log10(a)+log10(b)
        l=s+1;
        printf("%d\n",l);
    }
    return 0;
}
