#include <bits/stdc++.h>
using namespace std;
char s[12];
int cnt,ans[4],vis[130];
int main()
{
    while(cin>>s+1)//������һλ������������һλ����ǰ��0��1��ǰͷ����/0����������abc����ᡰ\000abc\000\000
    {
        memset(vis,0,sizeof(vis));
        s[0]=s[1];//�ͻ���aabc\000\000
        memset(ans,0,sizeof(ans));
        cnt=0;
        int n=strlen(s+1);//strlen(s+1)=3,strlen(s)=4
        for(int i=1;i<=n+1;i++)
        {
            vis[s[i]]++;//s[4]='\000'
            if(s[i]!=s[i-1])
                ans[++cnt]=vis[s[i-1]];
        }
        if(cnt!=3||(ans[2]!=ans[1]||ans[3]!=ans[1]||ans[1]!=ans[3]))
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
