#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    scanf("%d:%d", &a, &b);
    b += 30;
    if(b >= 60){
        a += 1;
        b -= 60;
    }
    a = (a + 3) % 24;
    printf("%02d:%02d\n", a, b);
    return 0;
}
