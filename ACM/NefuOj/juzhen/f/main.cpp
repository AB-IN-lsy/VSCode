#include <bits/stdc++.h>
using namespace std;
const int MAX = 4;
const int mod=10007;
typedef long long ll;
typedef struct{
    ll m[MAX][MAX];
}Matrix;

Matrix P;//构造出的矩阵

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
ll n,x,y,ans;
int main()
{
    while(cin>>n>>x>>y){
        ans=0;
        ll x_2=(x*x)%mod;
        ll y_2=(y*y)%mod;
        ll xy=(2*x*y)%mod;
        P={1,1,0,0,
           0,x_2,y_2,xy,
           0,1,0,0,
           0,x,0,y};
        Matrix tmp=quickpow(P,n);
        for(int i=0;i<4;i++){
            ans=(ans+tmp.m[0][i])%mod;
        }
        printf("%lld\n",ans%mod);
    }

    return 0;
}
