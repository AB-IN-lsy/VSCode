/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-11 09:34:20
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-11 09:37:14
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

int a[10], vis[10];
int main()
{
    IOS;
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        vis[a[i]]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            if(vis[a[i] * a[j]]) ans += vis[a[i] * a[j]];
        }
    }   
    DEBUG(ans);
    return 0;
}