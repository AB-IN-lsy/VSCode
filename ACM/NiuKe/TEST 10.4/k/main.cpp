#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
typedef long long ll;
string str[maxn];
int n,l,k,m=0,flag=0,now;
int main()
{
	scanf("%d%d%d",&n,&l,&k);
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	if(k==1)
	{
		for(int i=1;i<=l;++i) str[k]+=s[m],m++;
	}
	else{
			for(int i=1;i<=k;++i) str[i]+=s[m],m++;
			int t=str[k].size();
			for(int i=1;i<=k;++i)
			{
				if(str[i][t-1]==str[k][t-1]) {now=i;break;}
			}
	while(str[k].size()<l)
	{
		if(now!=k)
		{
			for(int i=now;i<=k;++i) str[i]+=s[m],m++;
			t=str[k].size();
			for(int i=now;i<=k;++i) if(str[i][t-1]==str[k][t-1]) {now=i;break;}
		 }
		else {
			while(str[k].size()<l) str[k]+=s[m],m++;
			break;
		}
	}
	}
	for(int i=1;i<=n;++i)
	{
		while(str[i].size()<l) str[i]+=s[m],m++;
	}
	for(int i=1;i<=n;++i) cout<<str[i]<<endl;
}
