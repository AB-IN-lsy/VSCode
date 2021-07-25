#include<cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
#define ll long long
const int maxn=1e5+5;
int maxx[maxn], pos[maxn], a[maxn];

struct aa
{
	int x, y, v;
	bool operator <(const aa&b) const{
		if (x==b.x) return y>b.y;
		return x<b.x;
	}
}p[maxn];

int lowbit(int x)
{
    return x&(-x);
}
void add(int pos,int val)
{
    for(int i=pos;i<=maxn;i+=lowbit(i))
        maxx[i]=max(maxx[i],val);
}
int query(int pos)
{
    int ans=0;
    for(int i=pos;i>=1;i-=lowbit(i))
        ans=max(ans,maxx[i]);
    return ans;
}

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
        memset(maxx,0,sizeof(maxx));         //树状数组清零
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
		{
			scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].v);
			a[i]=p[i].y;
		}
		sort(a+1, a+n+1);
		int all=unique(a+1, a+n+1)-a-1;
		for (int i=1; i<=n; i++) p[i].y=lower_bound(a+1, a+all+1, p[i].y)-a;  //离散化
		sort(p+1, p+n+1);
		for (int i=1; i<=n; i++)
		{
			int val=query(p[i].y-1)+p[i].v;
			add(p[i].y , val);
		}
		printf("%d\n", query(all));
	}

	return 0;
}
