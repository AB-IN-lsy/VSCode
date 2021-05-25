#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N=1e6+10;
char s[N];
int n,ne[N];
void get_ne()//打表next数组
{
    memset(ne,0,sizeof(ne));//ne[1]=0
    n=strlen(s+1);
    int j=0;
    for(int i=1;i<n;i++)
    {
        while(j!=0&&s[i+1]!=s[j+1])j=ne[j];
        if(s[i+1]==s[j+1])ne[i+1]=++j;
        else ne[i+1]=j;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>s+1&&s[1]!='.')
    {
        get_ne();
        if(n%(n-ne[n])==0)printf("%d\n",n/(n-ne[n]));
        else printf("1\n");
    }
    return 0;
}
