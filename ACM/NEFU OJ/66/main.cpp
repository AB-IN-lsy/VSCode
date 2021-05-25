#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,ans;
    while(cin>>t){
        while(t--){
            cin>>n;
            int k=n*log10(n)+1;
            double num=n*log10(n)-k+1;//num为double
            ans=pow(10,num);
            cout<<ans<<endl;
        }

    }
    return 0;
}
//n的n次方=d.yyyyy  *  10的（k-1）次方   其中k是数的位数
//log10(n的n次方)=log10(d.yyyy)+k-1
//log10(d.yyyy)=n*log10(n)-k+1
//d.yyyy=pow(10,n*log10(n)-k+1)
//其中k=n*log10(n)+1;
