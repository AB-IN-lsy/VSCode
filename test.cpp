#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

namespace union_set{
    const int N = 1e6 + 10;
    int fa[N], n, d[N], ans = N;
    void init ()
    {
        for(int i = 1;i <= n; i++) fa[i] = i;
    }
    int find(int x) 
    {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    void join(int a,int b)
    {
        int a1 = find(a),b1 = find(b);
        if(a1 != b1) {
            fa[a1] = b1;
            d[a] = d[b] + 1;
        }
        else{
            ans = min(ans, d[a] + d[b] + 1);
        }
    }
}
using namespace union_set;

int main()
{
    IOS;
    int x;
    cin >> n;
    init();
    for(int i = 1; i <= n; i ++){
        cin >> x;
        join(i, x); // i -> x 的有向边
    }
    cout << ans << '\n';
    return 0;
}