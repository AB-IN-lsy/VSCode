#include<bits/stdc++.h>
using namespace std;
void dfs(string mid,string aft){
    if(mid.size()==0)
        return;
    cout<<aft[aft.size()-1];
    int num=mid.find(aft[aft.size()-1]);
    dfs(mid.substr(0,num),aft.substr(0,num));
    dfs(mid.substr(num+1,mid.size()-1),aft.substr(num,mid.size()-num-1));
}
int main(){
    string mid,aft;
    cin>>mid>>aft;
    dfs(mid,aft);
    return 0;
}
