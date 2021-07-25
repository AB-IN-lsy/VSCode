#include <bits/stdc++.h>
#define  db double
using namespace std;
int n = 2;

db f(db x){
    return 4 / (1 + x * x);
}

db x_ans(db a, int k, db h){
    return a + k * (h / 2);
}

db solve(db a, db b, int n){
    db cnt1 = 0.0, cnt2 = 0.0;
    db h = (b - a) / n;
    for(int k = 1; k <= n; k++){
        cnt1 += f(x_ans(a, 2 * k - 1, h));
    }
    for(int k = 1; k <= n - 1; k++){
        cnt2 += f(x_ans(a, 2 * k, h));
    }

    return (db) h * (f(a) + 4 * cnt1 + 2 * cnt2 + f(b)) / 6.0;
}

int main()
{
    for(int i = 1; i <= 10; i++){
        printf("ans< %d > = %.10f\n", n, solve(0, 1, n) );
        n *= 2;
    }
    return 0;
}
