#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int cnt=0;
int prime[N];
bool b[N];
void init(){
    memset(b,1,sizeof(b));
    b[0]=b[1]=0;
    for(int i=2;i<=N;i++){
        if(b[i])
            prime[++cnt]=i;
            for(int j=1;j<=cnt&&prime[j]*i<=N;j++){
                b[prime[j]*i]=0;
                if(i%prime[j]==0)
                    break;
            }
    }
}
int n,ans1,ans2,A,B;
int main()
{
    init();
    cin>>A>>B;
    for(int i=A;i<=B;i++){
        ans1=0;ans2=0;
        int num=log10(i)+1;
        int i_1=i,i_2=i;
        for(int j=1;j<=num;j++){
            ans1+=i_1%10;
            i_1/=10;
        }
        int k=i_2;
        while(k){
            if(b[k]&&i_2%k==0&&k!=i)
            {
                i_2=i_2/k;
                int tmp=k;
                int num=log10(tmp)+1;
                for(int j=1;j<=num;j++){
                    ans2+=tmp%10;
                    tmp/=10;
                }
                k=i_2;
            }
            else
                k--;
        }
        if(ans1==ans2)
            cout<<i<<" ";
    }
    return 0;
}
