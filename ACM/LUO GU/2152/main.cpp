#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a,b,c;
    scanf("%llu%llu",&a,&b);
    c=__gcd(a,b);
    printf("%llu",c);
    return 0;
}
/*Õý¾­py3 AC´úÂë
import fractions
print(fractions.gcd(int(input()),int(input())))
*/
