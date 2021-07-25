#include <bits/stdc++.h>
using namespace std;
double n,k,jin,yin,tong;
int t;
int judge(double x)
{
    if(x-(int)x==0)
        return x;
    else
        return x+1;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf",&n,&k);
        int jin=judge(n*0.1);
        int yin=judge(n*0.2);
        int tong=judge(n*0.3);
        if(0<k&&k<=jin)
            printf("jin\n");
        else if(jin<k&&k<=yin+jin)
            printf("yin\n");
        else if(yin+jin<k&&k<=tong+jin+yin)
            printf("tong\n");
        else
            printf("tie\n");
    }
    return 0;
}
