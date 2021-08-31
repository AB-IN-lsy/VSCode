// Problem: Xor Sum
// Contest: Virtual Judge - HDU
// URL: https://vjudge.net/problem/HDU-4825
// Memory Limit: 132 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize(3)//O3
//#pragma GCC optimize(2)//O2
#include<iostream>
#include<string>
#include<map>
#include<set>
//#include<unordered_map>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<stack>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<fstream>
#define X first
#define Y second
#define best 131 
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define lowbit(x) x & -x
#define inf 0x3f3f3f3f
// #define int long long
//#define double long double
//#define rep(i,x,y) for(register int i = x; i <= y;++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double pai=acos(-1.0);
const int maxn=1e5+10;
const int mod=998244353;
const double eps=1e-9;
const int N=5e3+10;
/*--------------------------------------------*/
inline int read()
{
    int k = 0, f = 1 ;
    char c = getchar() ;
    while(!isdigit(c)){if(c == '-') f = -1 ;c = getchar() ;}
    while(isdigit(c)) k = (k << 1) + (k << 3) + c - 48 ,c = getchar() ;
    return k * f ;
}
/*--------------------------------------------*/

int t[maxn*32][2],val[maxn*32];
int n,a[maxn],tot,m;
void init()
{
    memset(t,0,sizeof(t));
    tot=0;
}
void insert(int x)
{
	int p=0;
	for(int i=31;i>=0;i--)
	{
		int to=(x>>i)&1;
		if(!t[p][to])
		{
			t[p][to]=++tot;
			p=t[p][to];
			t[p][0]=t[p][1]=0;
		}
		else
			p=t[p][to];
	}
	val[p]=x;
}
int find(int x)
{
	int p=0;
	for(int i=31;i>=0;i--)
	{
		int to=(x>>i)&1;
		if(t[p][to^1])
			p=t[p][to^1];
		else
			p=t[p][to];
	}
	return val[p];
}

int main() 
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	int _;
	while(scanf("%d",&_)!=EOF)
	{
		for(int k=1;k<=_;k++)
		{
			init();
			scanf("%d%d",&n,&m);
			for(int i=1;i<=n;i++)
				scanf("%d",&a[i]),insert(a[i]);
			printf("Case #%d:\n",k);
			while(m--)
			{
				int s;
				scanf("%d",&s);
				printf("%d\n",find(s));
			}
		}
	}
    return 0;
} 
