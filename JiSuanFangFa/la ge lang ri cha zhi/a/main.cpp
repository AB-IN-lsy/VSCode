#include <bits/stdc++.h>

using namespace std;
double x[]={0.4,0.5,0.6,0.7,0.8};
double f[]={0.38942,0.47943,0.56464,0.64422,0.71736};
double x_k;
int main()
{
    while(~scanf("%lf",&x_k)){
        double tmp = 1.0 , ans = 0.0;
        for(int i = 0 ;i <= 4; i++){
            tmp = 1.0;
            for(int j = 0;j <= 4;j++){
                if(j == i) continue;
                tmp *= (x_k - x[j]) / (x[i] - x[j]);
            }
            ans += tmp * f[i];
        }
        printf("f(%f) = %f\n",x_k,ans);
    }
    return 0;
}
