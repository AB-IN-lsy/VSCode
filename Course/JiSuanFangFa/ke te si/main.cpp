#include <bits/stdc++.h>
#define  db double
using namespace std;
int n = 2;

db f(db x){
    return 4 / (1 + x * x);
}

db x_ans(db a, int k, db h){
    return a + k * (h / 4);
}

db solve(db a, db b, int n){
    db cnt1 = 0.0, cnt2 = 0.0, cnt3 = 0.0, cnt4 = 0.0;
    db h = (b - a) / n;
    for(int k = 1; k <= n; k++){
        cnt1 += f(x_ans(a, 4 * k - 3, h));
    }
    for(int k = 1; k <= n; k++){
        cnt2 += f(x_ans(a, 4 * k - 2, h));
    }
    for(int k = 1; k <= n; k++){
        cnt3 += f(x_ans(a, 4 * k - 1, h));
    }
    for(int k = 1; k <= n - 1; k++){
        cnt4 += f(x_ans(a, 4 * k, h));
    }

    return (db) h * (7 * f(a) + 32 * cnt1 + 12 * cnt2 + 32 * cnt3 + 14 * cnt4 + 7 * f(b)) / 90.0;
}

int main()
{
    for(int i = 1; i <= 10; i++){
        printf("ans< %d > = %.10f\n", n, solve(0, 1, n) );
        n *= 2;
    }
    return 0;
}
