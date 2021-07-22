/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-23 02:12:56
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-23 03:04:28
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const int N = 5010;
bool dp[N][N];

int main()
{
    dp[0][0] = 0; // start from 00, Alice lose
    for(int i = 0; i <= 5000; i++){
        for(int j = i; j <= 5000; j++){ // j >= i
            if(!dp[i][j]){ // if Alice definitely lose
                
                for(int k = 1; i + k <= 5000; k ++){
                    for(int s = 0; j + k * s <= 5000; s ++){
                        int mx = max(i + k, j + k * s);
                        int mn = min(i + k, j + k * s);
                        dp[mn][mx] = 1; // Alice win, pick A st i ,pick B rd j
                    }
                }
                for(int k = 1; j + k <= 5000; k ++){
                    for(int s = 0; i + k * s <= 5000; s ++){
                        int mx = max(i + k * s, j + k);
                        int mn = min(i + k * s, j + k);
                        dp[mn][mx] = 1; // Alice win, pick B st j, pick A rd i
                    }
                }
                
            }
        }
    }
    int t, n, m;
    scanf("%d", &t);   
    while(t --){
        scanf("%d%d", &n, &m);
        if(n > m) swap(n, m);
        if(dp[n][m]) puts("Alice");
        else puts("Bob");
    } 
    return 0;
}