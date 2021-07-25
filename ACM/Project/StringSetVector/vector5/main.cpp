#include <bits/stdc++.h>
using namespace std;
map<string,int>a;//记用户的编号，变长数组没法用字符串记字符串，则采用map
map<int,string>b;//记id
vector<string>vis[1010];
string id,web;
int n,m,num,tmp;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int num=0;
    for(int i=1;i<=m;i++){
        if(!a[id])
        {
            num++;
            a[id]+=num;//num就为这个id的编号
            vis[num].push_back(web);//在编号后记上上网纪录
            b[num]=id;//纪录这个编号的id
        }
        else
        {
            tmp=a[id];
            vis[tmp].push_back(web);
        }
    for(int i=1;i<=num;i++){
        printf("%s ",b[i].c_str());
        for(int j=0;j<vis[i].size();j++){
            if(j==vis[i].size()-1)
                printf("%s\n",vis[i][j].c_str());
            else
                printf("%s ",vis[i][j].c_str());
        }
    }
    }
    return 0;
}
