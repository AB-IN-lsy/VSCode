#include <bits/stdc++.h>
using namespace std;
int p(int s)
{
    if ((int) pow((double) s,1/3) * (int) pow((double) s,1/3) * (int) pow((double) s,1/3) == s)
        return 1;
    else
        return 0;
}

int main()
{
	int i=0,j=0;
    int a[100];
    while(scanf("%d",&a[i])&&a[i]!=0){
      cout<<(int)pow((double) a[i],0.3333333);
      if(p(a[i])==1)
      ++j;
    }
    printf("%d",j);
}
