#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1000000+5
#define R register
#define ll long long
template <typename T>
inline void read(T &x)
{
        #define C getchar()
        char a=C;x=0;bool f=0;
        for(;a>'9'||a<'0';a=C) if(a=='-') f=1;
        for(;a>='0'&&a<='9';a=C) x=(x<<1)+(x<<3)+(a^48);
        if(f) x=-x;
}
int s[MAXN];int n;
long long sum[MAXN];
int main()
{
        while(~scanf("%d", &n))
        {
            for(R int i=1;i<=n;i++) read(s[i]),sum[i]=sum[i-1]+s[i];
            R ll ans=0,maxx=0,minn=0;
            for(R int i=1;i<=n;i++)
            {
                ll a1=sum[i]-minn,a2=sum[n]-(sum[i]-maxx);//最大子段和：总和减去最小子段和
                minn=min(minn,sum[i]);
                maxx=max(maxx,sum[i]);
                ans=max(ans,max(a1,a2));
            }
            printf("%lld\n",ans);
        }
        return 0;
}
