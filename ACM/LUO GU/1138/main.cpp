#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn=5e6+10;
ll n,k,a[maxn],ans;
int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ans=unique(a+1,a+n+1)-a;//������aȥ�أ�������ans=ȥ�غ��α�ĳ���
    if(k<ans)
        printf("%lld",a[k]);
    else
        printf("NO RESULT");
    return 0;
}
