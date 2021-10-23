/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-04 09:27:27
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-04 10:44:20
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const int N = 1e3 + 10;
int fa[N], du[N];

int t, n, s;

int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void join(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y) fa[x] = y;
}

int main()
{
    IOS;
    cin >> t;
    while(t --){
        memset(du, 0, sizeof du);
        cin >> n >> s;
        LL sum = 0;
        for(int i = 1; i <= n; i ++) fa[i] = i;
        for(int i = 2; i <= n; i ++){
            string str;
            cin >> str;
            for(int j = 0; j < SZ(str); j ++){
                if(str[j] == '0'){
                    join(i, j + 1);
                    du[i] += 1;
                    du[j + 1] += 1;
                    sum += 1;
                }
            }
        }
        int cnt_odd = 0;
        int cnt_block = 0; 
        for(int i = 1; i <= n; i ++){
            if(du[i] % 2) cnt_odd += 1;
            if(du[i] && fa[i] == i){
                cnt_block += 1;
            }
        }
        sum = sum + 2 * (cnt_block - 1);
        if(cnt_odd > 2) cout << -1 << '\n';
        else{
            if(du[s]){
                if(du[s] & 1){  
                    cout << sum << '\n';
                }
                else{
                    if(cnt_odd) cout << -1 << '\n';
                    else cout << sum << '\n';
                }
            }
            else{ 
                if(cnt_odd) cout << -1 << '\n'; 
                else cout << sum + 2 << '\n';
            }
        }
    }
    return 0;
}