#include <bits/stdc++.h>
using namespace std;
int n,k,ans=0;
void dfs(int last,int sum,int step)
{
     if(step>k)
        return;
     if (step==k){
        if (sum==n)
            ans++;
        return;
     }
     for(int i=last;sum+i*(k-step)<=n;i++)//1.若要保证递增顺序（不重复），则用for循环，从小到大递增找。
        //剪枝，2.因是递增的，后面的数比i大，若此时都>n了，则后面的情况肯定都大于n，因此剪枝
        dfs(i,sum+i,step+1);
    return;
}
int main()
{
    cin>>n>>k;
    dfs(1,0,0);
    cout<<ans<<endl;
    return 0;
}
