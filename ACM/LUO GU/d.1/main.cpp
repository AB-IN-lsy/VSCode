#include <iostream>
#define val 1000000000;
using namespace std;
const int MAX = 2;
typedef  struct{
        long long m[MAX][MAX];
}  Matrix;

Matrix P = {0,1,
            1,1
           };

Matrix I = {1,0,
            0,1
           };

Matrix matrixmul(Matrix a,Matrix b)
{
       int i,j,k;
       Matrix c;
       for (i = 0 ; i < MAX; i++)
           for (j = 0; j < MAX;j++)
             {
                 c.m[i][j] = 0;
                 for (k = 0; k < MAX; k++)
                     c.m[i][j] =(c.m[i][j]+(a.m[i][k]*b.m[k][j]))%val;
                 c.m[i][j] %= val;
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
    int a,b,ans,m=1000000000;
    Matrix c,c1;
   while(cin>>a>>b)
      {
      if (a==0&&b==0) break;

     c=quickpow(b+2);

     c1= quickpow(a+1);
     cout<<c1.m[0][0]<<endl;
     cout<<c1.m[0][1]<<endl;
     cout<<c.m[0][0]<<endl;
     cout<<c.m[0][1]<<endl;
     int sum=((c.m[0][0]-c1.m[0][0])%m+(c.m[0][1]-c1.m[0][1])%m)%m;
     //int sum1=c1.m[0][0]%m+c1.m[0][1]%m;

     ans=(sum)%m;
     if (ans<0) ans=ans+m;
     //cout<<ans<<endl;
   }
}
