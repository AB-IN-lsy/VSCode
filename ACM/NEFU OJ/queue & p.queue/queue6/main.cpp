#include <bits/stdc++.h>
const int minn=1e5+1;
using namespace std;
struct boat{
int t;//һ��Ҫ�����������˳�򣬶���ṹ���������Ȼ��RE
int x;
};//����Ū���飬���ü�¼x��t���¸����ݸ��Ǽ���
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
         q.push({t,x});//�Խṹ����ʽ��������У��ܶ�x��Ӧһ��t����һ��x��Ӧһ��t������һ����queue2
         if (num[x]==0)
            ans++;
         num[x]++;
     }
    struct boat tmp;
     while(t-q.front().t>=86400)//���ʶ��нṹ����ף�q.front().
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
