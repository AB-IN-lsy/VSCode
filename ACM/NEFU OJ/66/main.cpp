#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,ans;
    while(cin>>t){
        while(t--){
            cin>>n;
            int k=n*log10(n)+1;
            double num=n*log10(n)-k+1;//numΪdouble
            ans=pow(10,num);
            cout<<ans<<endl;
        }

    }
    return 0;
}
//n��n�η�=d.yyyyy  *  10�ģ�k-1���η�   ����k������λ��
//log10(n��n�η�)=log10(d.yyyy)+k-1
//log10(d.yyyy)=n*log10(n)-k+1
//d.yyyy=pow(10,n*log10(n)-k+1)
//����k=n*log10(n)+1;
