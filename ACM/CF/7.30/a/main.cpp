#include <bits/stdc++.h>

using namespace std;
long long t,a,p[10]={0,14,15,21,22,26,33},tmp1,tmp2;
int main()
{
    cin>>t;
    while(t--){
        cin>>a;
        if(a<=30){
            printf("NO\n");
            continue;
        }
        else{
            int tmp=a-6-10;
            for(int i=1;i<=7;i++){
                tmp1=tmp-p[i];
                tmp2=p[i];
                if(tmp1!=tmp2&&tmp1!=6&&tmp1!=10&&tmp1!=0)
                    break;
            }
            printf("YES\n");
            printf("6 10 %lld %lld\n",tmp2,tmp1);
        }
    }
    return 0;
}
