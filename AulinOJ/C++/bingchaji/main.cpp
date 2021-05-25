#include <bits/stdc++.h>
using namespace std;
int n, m, t, a, b, u, v;
int fa[1005];

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d %d", &n, &m, &t);
    for(int i = 1;i <= n; i++) fa[i] = i;
    for(int i = 1;i <= m; i++) {
        scanf("%d %d", &a, &b);
        u = find(a); v = find(b);
        fa[u] = v;
    }
    while(t--) {
        scanf("%d %d", &a, &b);
        u = find(a); v = find(b);
        if(u == v) puts("YES");
        else puts("NO");
    }
}
