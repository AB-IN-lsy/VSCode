#include <bits/stdc++.h>
#define lowbit(x) ((x) &-(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5, mod = 1e9 + 9;
int n, a[maxn], b[maxn], tree[maxn];
inline void add(ll x,ll d)
{
    while(x<=n){
        tree[x]=(tree[x]+d)%mod;
        x+=lowbit(x);//查询x的后继们
    }
}
ll sum(ll x)//前缀和
{
    ll sum=0;
    while(x>0){
        sum=(sum+tree[x])%mod;
        x-=lowbit(x);//查询x的前驱们
    }
    return sum;
}
int main () {
    cin >> n;
    rep(i,1,n){
        cin >> a[i];
        a[i] += a[i-1];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    rep(i,0,n)//注意这里是从0开始离散化，目的就是让sum[0]的地方变成最小的标号。
        a[i] = lower_bound(b+1, b+n+1, a[i]) - b ;//这个地方，如果是减b,那么最小下标从1开始，如果减b加1，那么最小下标从2开始。
    ll ans = 0;
    add(a[0],1);//先把基准加进去
    rep(i,1,n) {
        ans = sum(a[i]);//在逆序对那说过，这就是求小于等于我的数，其实就是sum(a[i])-sum(a[i之前下标])>=0的数量
        add(a[i], ans);
    }
    cout << ans << endl;
    return 0;
}
