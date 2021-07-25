#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e8+10;
int cnt=0;
int prime[5000010];
bool b[N];
int init(int n){//筛出素数数组
    memset(b,1,sizeof(b));
    b[0]=b[1]=0;
    for(int i=2;i<=n;i++){
        if(b[i])
            prime[++cnt]=i;
            for(int j=1;j<=cnt&&prime[j]*i<=n;j++){
                b[prime[j]*i]=0;
                if(i%prime[j]==0)
                    break;
            }
    }
    return 0;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    init(n);
    while (q--)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", prime[k]);
    }
    return 0;
}
