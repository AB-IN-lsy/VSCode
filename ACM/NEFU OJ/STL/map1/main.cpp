#include <bits/stdc++.h>
using namespace std;
map<string,int>vis;
int main()
{
    ios::sync_with_stdio(false);
    int n,yema;
    string word;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>word>>yema;
        vis[word]+=yema;
    }
    int x;
    cin>>x;
    for(int i=1;i<=x;i++){
        cin>>word;
        cout<<vis[word]<<endl;
    }
    return 0;
}
