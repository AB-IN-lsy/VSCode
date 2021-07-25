#include <bits/stdc++.h>
using namespace std;
int a[10010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        a[i]=i;
    do{
        for(int i=1;i<=n;i++)
            printf("%5d",a[i]);
        cout<<endl;
    }while(next_permutation(a+1,a+n+1));
    return 0;
}
