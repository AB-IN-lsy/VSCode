#include <bits/stdc++.h>

using namespace std;
vector<int>vis;
int main()
{
    int x;
    while(cin>>x&&x){//���뵽0����
        vis.push_back(x);//��ʼ��
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
