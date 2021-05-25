#include <bits/stdc++.h>

using namespace std;
#define MIN 0.5*1e-6
int main()
{
    double x_o=1.0,x=0.0,cha=0.0;
    do{
        x=(2.0/3.0)*x_o+1.0/pow(x_o,2);
        cha=fabs(x-x_o);
        printf("x_o=%.15f x=%.15f cha=%.15f\n",x_o,x,cha);
        x_o=x;
    }while(cha>MIN);
    return 0;
}
