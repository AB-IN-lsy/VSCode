/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-06-13 08:25:09
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-06-13 10:21:26
 */
#include<bits/stdc++.h>
using namespace std;
int a[100005];//记录节点个数
int fa[100005];//记录父节点
int dui[20005];//ans记录答案，dui记录w的值
long long ans[200005];
long long sum;
int cnt;
struct sa{
    int u, v, w;
} s[200005];
bool cmp(const struct sa &a, const struct sa &b)
{
    return a.w > b.w;
}
int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void join(int x, int y)
{
    int a1=find(x),b1=find(y);
    if(a1!=b1) {
        sum-=(long long)a[a1]*(a[a1]-1)/2;
        sum-=(long long)a[b1]*(a[b1]-1)/2;
        a[a1]+=a[b1];a[b1]=0;fa[b1]=a1;
        sum+=(long long)a[a1]*(a[a1]-1)/2;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t --){
        sum=cnt=0;
        int n, m, q, k;
        for(int i=1;i<=n;i++) fa[i]=i;
        cin >> n >> m >> q;
        for(int i=1;i<=n;i++) a[i]=1;
        for(int i = 1; i <= m; i ++){
            cin >> s[i].u >> s[i].v >> s[i].w;
        }
        sort(s+1, s+1+m, cmp);
        int currentw=s[1].w;
        for(int i=1;i<=m;i++){
            if(currentw != s[i].w){
                dui[++cnt] = currentw;
                ans[cnt] = sum;
                currentw = s[i].w;
                join(s[i].u,s[i].v);
            }
            else{
                join(s[i].u,s[i].v);
            }
        }
        while(q--){
            cin>>k;
            int index = upper_bound(dui + 1, dui + 1 + cnt, k, greater<int>()) - dui;
            cout << ans[index] << '\n';
        }
    }
}