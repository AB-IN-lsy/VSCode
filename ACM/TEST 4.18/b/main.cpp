#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[101000];
int main()
{
    ll n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int id1 = upper_bound(a + i + 1, a + 1 + n, abs(a[i] - x)) - a;
        int id2 = lower_bound(a + i + 1, a + 1 + n, a[i] + x) - a;
        id2 --;
        if(id2 >= id1)
        ans += (id2 - id1 + 1);
    }
    cout << ans << endl;
    return 0;
}
