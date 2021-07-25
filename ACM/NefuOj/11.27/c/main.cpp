#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
const int N = 1e5 + 10;
int n, cnt;
ll x, y;
ll a[N];
int main()
{
    IOS;
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int s2 = 0;
    int id1 = n, id2 = n;
    for(int i = 1; i <= n; i++){
        while(id1 >= 1 && a[i]+a[id1] >= x) id1--;
        while(id2 >= 1 && a[i]+a[id2] > y) id2--;
        cnt += (id2 - id1);
        if(a[i]*2>=x&&a[i]*2<=y)
            s2++;
    }
    cout << (cnt - s2) / 2 << endl;
}
