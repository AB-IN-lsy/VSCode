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
/*����py3 AC����
import fractions
print(fractions.gcd(int(input()),int(input())))
*/
