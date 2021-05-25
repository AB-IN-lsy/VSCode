#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
int n, m;
const int inf = 0x3f3f3f3f;
ll a[N], x, d[N];

struct sa
{
    ll d;
    ll v;
    bool operator <(const sa &b) const {
        return b.v < v;
    }
}b[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i].d;
    for(int i = 1; i <= m; i++) cin >> b[i].v;

    sort(b + 1, b + 1 + m);
    for(int i = 1; i <= m; i++) {
        if(b[i].v >= 0) d[i] = b[i].d;
        else d[i] = inf;
    }
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        int tmp = upper_bound(d + 1, d + m + 1, a[i] , greater<int>() ) - d;
        sum += b[tmp].v;
    }

    cout << sum << endl;
    return 0;
}
//

//
