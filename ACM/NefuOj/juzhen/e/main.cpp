#include <bits/stdc++.h>
using namespace std;
const int MAX = 3;
const int mod=1e7;
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
ll t,a,b,p,q,s,e,ans1,ans2;
int main()
{
    cin>>t;
    while(t--){
        cin>>a>>b>>p>>q>>s>>e;
        P={1,p,q,0,p,q,0,1,0};
        if(e==0) ans1=a;
        else{
            Matrix tmp=quickpow(P,e-1);
            ans1=(tmp.m[0][0]*(a+b)+tmp.m[0][1]*b+tmp.m[0][2]*a)%mod;
        }
        if(s==0) ans2=0;
        else if(s==1) ans2=a;
        else{
            Matrix tmp=quickpow(P,s-2);
            ans2=(tmp.m[0][0]*(a+b)+tmp.m[0][1]*b+tmp.m[0][2]*a)%mod;
        }
        printf("%lld\n",((ans1-ans2)%mod+mod)%mod);
    }

    return 0;
}
