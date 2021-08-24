/*
 * @Author: NEFU AB_IN
 * @Date: 2021-07-16 18:21:31
 * @FilePath: \Vscode\test.cpp
 * @LastEditTime: 2021-08-21 21:17:36
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

const int N = 3e3 + 10;

const LL mod = 1e9 + 7;
LL mul(LL x, LL y){return 1LL * x * y % mod;}
LL dec(LL x, LL y){return x >= y ? x - y : x + mod - y;}
LL add(LL x, LL y){return x + y >= mod ? x + y - mod : x + y;}
LL pmod(LL x) {return (x + mod) % mod;}

LL s[N][N], fac[N];
void init(){
    memset(s,0,sizeof(s));
    s[1][1]=1;
    for(int i=2;i<=N-1;i++){
        for(int j=1;j<=i;j++){
            s[i][j]=s[i-1][j-1]+j*s[i-1][j];
            if(s[i][j]>=mod)
                s[i][j]%=mod;
        }
    }
    fac[0] = 1;
    for(int i = 1; i <= N; i ++){
        fac[i] = fac[i - 1] * i % mod;
    }
}

signed main()
{
    IOS;
    int t;
    init();
    cin >> t;
    while(t --){
        LL n, k;
        cin >> n >> k;
        LL ans = 0;
        for(int i = 1; i <= n; i ++){
            ans = add(ans, mul(mul(s[n][i], s[n][i]), mul(fac[i - 1], fac[i - 1])));
        }
        cout << ans << '\n';
    }
    return 0;
}