/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-31 12:55:17
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-31 14:31:05
 */
#include <bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

int read() {
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}
const int N = 1e5 + 10;

int n, m;
int k;
int maxsum[N][30];
int minsum[N][30];
int Log[N]; // 用来求log的
int a[N];

void log_init() // 求log的函数
{ 
    Log[1] = 0;
    for(int i = 2; i <= n; i++)
        Log[i] = Log[i / 2] + 1;
}

void rmq_init()
{
    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            maxsum[i][j] = max(maxsum[i][j - 1], maxsum[i + (1 << (j - 1))][j - 1]);
            minsum[i][j] = min(minsum[i][j - 1], minsum[i + (1 << (j - 1))][j - 1]);
        }
}

int query(int l, int r)
{
    int k = Log[r - l + 1];
    int Max = max(maxsum[l][k], maxsum[r - (1 << k) + 1][k]);
    int Min = min(minsum[l][k], minsum[r - (1 << k) + 1][k]);
    return Max - Min;
}

int main()
{
    //scanf("%d%d", &n, &m);
    n = read(); m = read();
    for (int i = 1; i <= n; ++i)
    {
        //scanf("%d", a + i);
        a[i] = read();
        maxsum[i][0] = minsum[i][0] = a[i];
    }
    log_init();
    rmq_init();
    while(m --){
        //scanf("%d", &k);
        k = read();
        LL ans = 0;
        int l = 1, r = 1;
        while(l <= n && r <= n){
            int cha = query(l, r);
            if(cha <= k){
                r ++;
            }
            else{
                ans +=(n - r + 1);
                l ++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}