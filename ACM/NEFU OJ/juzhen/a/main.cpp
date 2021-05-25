#include <bits/stdc++.h>
using namespace std;
const int MAX = 10;
typedef long long ll;
typedef struct{
    ll m[MAX][MAX];
}Matrix;

Matrix P;//构造出的矩阵

ll k,mod,a[MAX];
Matrix matrixmul(Matrix a,Matrix b) //矩阵乘法
{
    int i,j,k;
    Matrix c;
    for (i = 0 ; i < MAX; i++)
        for (j = 0; j < MAX;j++)
        {
            c.m[i][j] = 0;
            for (k = 0; k < MAX; k++)
                c.m[i][j] =(c.m[i][j]+(a.m[i][k]*b.m[k][j]))%mod;
            c.m[i][j] %=mod;
        }
    return c;
}

Matrix quickpow(Matrix m , ll n)
{
    Matrix b;//单位矩阵在这构造也可以
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
        {
            if(i==j)b.m[i][j]=1;
            else b.m[i][j]=0;
        }
    while (n >= 1)
    {
        if (n & 1)
                b = matrixmul(b,m);
        n = n >> 1;
        m = matrixmul(m,m);
    }
    return b;
}
int main()
{
    while(cin>>k>>mod){
        for(int i=0;i<MAX;i++){
            cin>>a[i];
            P.m[0][i]=a[i];
            if(i>=1) P.m[i][i-1]=1;
        }
        if(k<10){printf("%lld\n",a[k]%mod);continue;}
        else{
            Matrix tmp=quickpow(P,k-9);
            ll ans=0;
            for(int i=0;i<MAX;i++){
                ans=(ans+tmp.m[0][i]*(9-i)%mod)%mod;
            }
            printf("%lld\n",ans%mod);
        }
    }
    return 0;
}
