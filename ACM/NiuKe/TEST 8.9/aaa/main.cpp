#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
pair<int,int> p[N];
int main() {
    int n,m,l,r;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        cin >> l >> r;
        p[i] = {l,r};
    }
    sort(p,p+m);
    int maxn = 0,now = 0;
    for(int i=0;i<m;i++) {
        if(now < p[i].first) {
            maxn = max(maxn,p[i].first - now - 1);
        }
            now = max(now,p[i].second);
    }
    maxn = max(maxn,n-now);
    cout << maxn;
    return 0;
}
