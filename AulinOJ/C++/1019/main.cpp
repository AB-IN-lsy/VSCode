#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k=1,n;
	scanf("%d",&n);
	while(n-k>0)
	{
		n-=k;
		k++;
	}
	if(k%2==0)
        printf("%d/%d",n,k+1-n);
	else
	    printf("%d/%d",k+1-n,n);
    return 0;
}
