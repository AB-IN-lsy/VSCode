#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
float f(float x)
{
    return 4/(1+x*x);
}
float Simpson(float(*f)(float),float a,float b,int n)
{
    int k;
    float I,s1,s2=0.0;
    float h=(b-a)/n;
    s1=f(a+h/2);
    for(k=1;k<=n-1;k++)
    {
        s1+=f(a+k*h+h/2);
        s2+=f(a+k*h);
    }
    I=h/6*(f(a)+4*s1+2*s2+f(b));
    return I;
}

int main()
{
    int i,n=2;
    float I;
    float f(float x);
    float Simpson(float(*f)(float),float a,float b,int n);
    for(i=0;i<=2;i++)
    {
        I=Simpson(f,0,1,n);
        printf("I(%d)=%f\n",n,I);
        n*=2;
    }
    return 0;
}
