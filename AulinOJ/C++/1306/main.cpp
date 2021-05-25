#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF,n)
	{
		printf("%.lf\n",ceil(log(n*1.0)/log(3.0)));
	}
}
