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
        x+=lowbit(x);//��ѯx�ĺ����
    }
}
ll sum(ll x)//ǰ׺��
{
    ll sum=0;
    while(x>0){
        sum=(sum+tree[x])%mod;
        x-=lowbit(x);//��ѯx��ǰ����
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
    rep(i,0,n)//ע�������Ǵ�0��ʼ��ɢ����Ŀ�ľ�����sum[0]�ĵط������С�ı�š�
        a[i] = lower_bound(b+1, b+n+1, a[i]) - b ;//����ط�������Ǽ�b,��ô��С�±��1��ʼ�������b��1����ô��С�±��2��ʼ��
    ll ans = 0;
    add(a[0],1);//�Ȱѻ�׼�ӽ�ȥ
    rep(i,1,n) {
        ans = sum(a[i]);//���������˵�����������С�ڵ����ҵ�������ʵ����sum(a[i])-sum(a[i֮ǰ�±�])>=0������
        add(a[i], ans);
    }
    cout << ans << endl;
    return 0;
}
