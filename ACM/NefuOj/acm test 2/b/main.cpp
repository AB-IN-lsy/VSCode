#include <bits/stdc++.h>
using namespace std;
int n;
double a[100001],s1,s2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf",&a[i]);
    sort(a+1,a+1+n);
    while(scanf("%lf%lf",&s1,&s2)!=EOF){
        int ans1=lower_bound(a+1,a+n+1,s1)-a;
        int ans2=upper_bound(a+1,a+n+1,s2)-a;
        printf("%d\n",ans2-ans1);
    }
    return 0;
}
