#include <bits/stdc++.h>

using namespace std;
vector<int>vis;
int main()
{
    int x;
    while(cin>>x&&x){//输入到0结束
        vis.push_back(x);//初始化
    }
    int num=vis.size();
    if(num%2==0){
        cout<<vis[num/2-1]+vis[num/2]<<endl;
    }
    if(num%2!=0){
        cout<<vis[num/2]<<endl;
    }
    return 0;
}
