#include<bits/stdc++.h>
using namespace std;

int i,n,r,f,Q[600005];
long long ans=0;
char R[300005][5];
int main()
{
    scanf("%d",&n);
    for(i = n; i >= 1;i--) scanf("%s",R[i]);
    for(i = 1; i <= n;i++)
    {
    	if(R[i][0] != 'x') Q[r++] = i;
    	if(R[i][1] != 'x') Q[r++] = i;
    	if(R[i][0] == 'o') ans += i - Q[f++];
    	if(R[i][1] == 'o') ans += i - Q[f++];
    	if((R[i][0]=='x'&&R[i][1]=='x')||(R[i][0]=='x'&&R[i+1][1]=='x')||(R[i+1][0]=='x'&&R[i][1]=='x')) r = f = 0;
	}
	printf("%lld\n",ans);
    return 0;
}
