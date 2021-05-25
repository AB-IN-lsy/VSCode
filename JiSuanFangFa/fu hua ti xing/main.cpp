#include <bits/stdc++.h>
#define  db double
using namespace std;

db f(db x){
    return 4 / (1 + x * x);
}

db solve(db a, db b, int n){
    db cnt = 0.0;
    db h = (b - a) / n;
    for(int i = 1; i <= n - 1; i++){
        cnt += f(a + i * h);
    }
    return (db) h * (f(a) + 2 * cnt + f(b)) / 2.0;
}

int n = 2;
int main()
{
    for(int i = 1; i <= 20; i++){
        printf("ans< %d > = %.10f\n", n, solve(0, 1, n) );
        n *= 2;
    }
    return 0;
}
