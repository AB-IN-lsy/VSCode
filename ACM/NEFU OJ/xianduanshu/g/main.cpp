#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) &-(x))
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
int n,m,left_tree[1000000],right_tree[1000000],l,r,op1;

inline void add_l(int x,int d)
{
    while(x<=n){
        left_tree[x]+=d;
        x+=lowbit(x);
    }
}
inline void add_r(int x,int d)
{
    while(x<=n){
        right_tree[x]+=d;
        x+=lowbit(x);
    }
}
int sum_l(int x)
{
    int sum=0;
    while(x>0){
        sum+=left_tree[x];
        x-=lowbit(x);
    }
    return sum;
}
int sum_r(int x)
{
    int sum=0;
    while(x>0){
        sum+=right_tree[x];
        x-=lowbit(x);
    }
    return sum;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&op1,&l,&r);
		if(op1==1){
			add_l(l,1);
			add_r(r,1);
		}
		 else printf("%d\n",sum_l(r)-sum_r(l-1));
	}
}
