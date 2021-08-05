/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-26 12:57:24
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-04 16:21:17
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const int N = 10;
int fa[N];
int sig[N];
int n, m;

int find(int x) {
    return fa[x] == x ? x : find(fa[x]);
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) {
        fa[fx] = fy;
        if(sig[fx]) sig[fy] += sig[fx];
    } else {
        sig[fx] ++;
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        merge(x, y); 
    }
    int cnt = 0;
    int huan = 0;
    for(int i = 1; i <= n; i++) {
        if(i == fa[i]) {
            cnt ++;
            huan += sig[i];
        }
    }
    cout << "cnt:" << cnt << '\n';
    cout << "huan:" << huan << '\n';

    if((cnt + huan) & 1) puts("Alice");
    else puts("Bob");
    return 0;
}
/*
5 6
1 2
2 3
1 3
3 4
4 5
3 5

5 6
1 3
3 2
1 2
3 4
4 5
3 5

6 7
1 2
2 3
3 4
1 4
3 5
5 6
3 6

5 5
1 2
3 4
2 3
1 4
3 5
*/