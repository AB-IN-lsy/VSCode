/*
 * @Description: https://blog.csdn.net/qq_45859188
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-05-09 17:00:35
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-05-09 21:20:45
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define MP                          make_pair
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int base = 131, N = 1e5 + 10;
ULL h[N], p[N], g[N];
int n, m, x;
int wid[N], ans[N], st[N];

ULL get(int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}

bool dfs(int u, int id){ // u是第几个，id是字符串目前起始位置
    if(id == n) return true;
    for(int i = 1; i <= m; i ++){
        if(!st[i] && g[i] == get(id, id + wid[i] - 1)){
            st[i] = 1;
            ans[u] = i;
            dfs(u + 1, id + wid[i] - 1); // 因为有一个是重叠的部分，所以起始位点是前一个串的最后一个字符
            st[i] = 0;
            // ans不用回溯，会覆盖的
        }
    }
    return false;
}


int main()
{
    IOS;
    cin >> n;
    p[0] = 1;
    for(int i = 1; i <= n; i ++){
        cin >> x;
        h[i] = h[i - 1] * base + x + 1;
        p[i] = p[i - 1] * base;
    }
    cin >> m;
    for(int i = 1; i <= m; i ++){
        cin >> wid[i];
        for(int j = 1; j <= wid[i]; j ++){
            cin >> x;
            g[i] = g[i] * base + x + 1;
        }
    }
    dfs(1, 1);
    for(int i = 1; i <= m; i ++){
        cout << ans[i] << (i == m ? "" : " ");
    }
    return 0;
}