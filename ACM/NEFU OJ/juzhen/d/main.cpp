#include <bits/stdc++.h>
using namespace std;
const int MAX = 2;
const int mod=1000000000;
typedef long long ll;
typedef struct{
    ll m[MAX][MAX];
}Matrix;

Matrix P = {1,1,
            1,0//推出来的矩阵
};
Matrix I = {1,0,//单位阵
            0,1
};

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

Matrix quickpow(ll n)
{
    Matrix m = P, b = I;
    while (n >= 1)
    {
        if (n & 1)
                b = matrixmul(b,m);
        n = n >> 1;
        m = matrixmul(m,m);
    }
    return b;
}
ll a,b;
int main()
{
    while(cin>>a>>b){
        if(a==0&&b==0)
            break;
        Matrix tmp1,tmp2;
        tmp1=quickpow(a+1);
        tmp2=quickpow(b+2);
        int ans=((tmp2.m[1][0]-tmp1.m[1][0])%mod+(tmp2.m[1][1]-tmp1.m[1][1])%mod)%mod;
        cout<<(ans+mod)%mod<<endl;
        }
    return 0;
}
