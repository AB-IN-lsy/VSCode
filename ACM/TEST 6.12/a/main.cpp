#include <iostream>
#define ll      long long

using namespace std;
const int N = 1e5 + 10;

struct sa{
    ll s, v, l;
}car[N];


int main()
{
    int n;
    while(cin >> n){
        for(int i = 0; i <= n; i ++) cin >> car[i].l;
        for(int i = 0; i <= n; i ++) cin >> car[i].s;
        for(int i = 0; i <= n; i ++) cin >> car[i].v;
        double ans = 0.0;
        ll sum = 0;
        for(int i = 1; i <= n; i ++) sum += car[i].l;
        for(int i = n; i >= 0; i --){
            double t = (sum * 1.0 + car[i].s * 1.0) / (car[i].v * 1.0);
            sum -= car[i].l;
            ans = max(ans, t);
            //cout<<ans<<endl;
        }
        printf("%.10f\n", ans);
    }
    return 0;
}

