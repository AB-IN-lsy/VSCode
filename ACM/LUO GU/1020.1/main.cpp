#include<bits/stdc++.h>
using namespace std;
int a,n,h[100005],cmax[100005],cmin[100005],ans1,ans2,maxx;
int lowbit(int x)
{
	return x&(-x);
}
void update1(int x,int w)
{
	while(x>0)
	{
		cmin[x]=max(cmin[x],w);
		x-=lowbit(x);
	}
}
void update2(int x,int w)
{
	while(x<=maxx)
	{
		cmax[x]=max(cmax[x],w);
		x+=lowbit(x);
	}
}
int sum1(int x)
{
	int res=0;
	while(x<=maxx)
	{
		res=max(res,cmin[x]);
		x+=lowbit(x);
	}
	return res;
}
int sum2(int x)
{
	int res=0;
	while(x>0)
	{
		res=max(res,cmax[x]);
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	while(scanf("%d",&a)!=EOF)
	{
		h[++n]=a;
		maxx=max(a,maxx);
	}
	for(int i=1;i<=n;i++)
	{
		int p1=sum1(h[i]),p2=sum2(h[i]);
		ans1=max(ans1,p1+1);
		ans2=max(ans2,p2+1);
		update1(h[i],p1+1);
		update2(h[i]+1,p2+1);
	}
	cout<<ans1<<" "<<ans2<<endl;
}
