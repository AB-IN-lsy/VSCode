#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll x,y;
int main()
{
    scanf("%lld%lld",&x,&y);
    double a=log10(pow(x,y)/pow(y,x));
    if(a>0) printf(">\n");
    else if (a<0) printf("<\n");
    else printf("=\n");
    return 0;
}
