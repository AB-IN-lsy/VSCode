#include <bits/stdc++.h>
using namespace std;
const int MAX = 3;
const int mod=9997;
typedef struct{
    int m[MAX][MAX];
}Matrix;

Matrix P = {5,-7,4,//推出来的矩阵
            1,0,0,
            0,1,0,
};
Matrix I = {1,0,0,//单位阵
            0,1,0,
            0,0,1,
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
                c.m[i][j] += (a.m[i][k] * b.m[k][j])%mod;
            c.m[i][j] %=mod;
        }
    return c;
}

Matrix quickpow(long long n)
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
int main()
{

    return 0;
}
