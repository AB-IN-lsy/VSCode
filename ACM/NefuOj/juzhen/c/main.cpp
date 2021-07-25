#include <bits/stdc++.h>
const int maxn=100;
using namespace std;

inline int f(int x) {
	if (x == 1 || x == 2) return 1;
	else return f(x - 1) + f(x - 2);
};
int c(int n,int k){
    if (n==k||k==0)
	{
		return 1;
	}
	else
	{
		return c(n-1,k)+c(n-1,k-1);
	}
}
int ans;

int main()
{
    for(int i=1;i<=10;i++){
        ans=0;
        printf("f(%d)=%d   ",i,f(i));
        for(int j=1;j<=i;j++){
            ans+=(f(j)*c(i,j));
        }
        printf("s(%d)=%d\n",i,ans);
    }
    // f(1)=1;f(2)=1;f(3)=2;f(4)=3
    // s(1)=1;s(2)=3;
    return 0;
}
