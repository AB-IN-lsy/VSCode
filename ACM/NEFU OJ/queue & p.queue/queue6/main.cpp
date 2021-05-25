#include <bits/stdc++.h>
const int minn=1e5+1;
using namespace std;
struct boat{
int t;//一定要按下面输入的顺序，定义结构体的数，不然会RE
int x;
};//不用弄数组，因不用记录x与t，下个数据覆盖即可
queue<boat>q;
int n,t,k,x,ans;
int num[minn];
int main()
{
    //ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>t>>k;
     for(int j=1;j<=k;j++){
         cin>>x;
         q.push({t,x});//以结构体形式输入队列中，很多x对应一个t，若一个x对应一个t，见另一个题queue2
         if (num[x]==0)
            ans++;
         num[x]++;
     }
    struct boat tmp;
     while(t-q.front().t>=86400)//访问队列结构体队首，q.front().
     {
        tmp=q.front();
        q.pop();
        int x1=tmp.x;
        num[x1]--;
        if (num[x1]==0)
            ans--;
     }  cout<<ans<<endl;

    }

    return 0;
}
