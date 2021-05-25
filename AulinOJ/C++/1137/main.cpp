#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N,m,i,x,d=0,j,tmp;
	int a[100];
	scanf("%d",&N);
	for(i=0;i<N;i++)
	    scanf("%d",&a[i]);
	scanf("%d",&m);
		for(i=0;i<N-1;i++)
		{
			for(j=0;j<N-1-i;j++)
			{
				if(a[j]<a[j+1])
				{
					tmp=a[j];
					a[j]=a[j+1];
					a[j+1]=tmp;
				}
			}
		}
     for(i=0;i<N;i++)
	 {
		 if(a[i]==m)
		 {
			 x=i;
			 break;
		 }
		 if(a[i]==a[i+1])
		   d++;
	}
	printf("%d\n",x+1-d);
    return 0;
}
