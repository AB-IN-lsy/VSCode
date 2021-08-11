#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN =  10;
int f[MAXN], ans[MAXN];
struct Q
{
    int l, r, c;
}que[MAXN];
int find(int x) {
    return f[x] == x ? x : f[x] == find(f[x]);
}
void solve(int num) {
    for (int i = num - 1; i >= 0; i--) {
        for (int j = find(que[i].l); j <= que[i].r; j = find(j)) {
            ans[j] = que[i].c;
            f[j] = j + 1;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n + 1; i++) {
        f[i] = i;
    }
    int num = q;
    for (int i = 0; i < q; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        que[i].l = l;
        que[i].r = r;
        que[i].c = c;
    }
    solve(q);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
