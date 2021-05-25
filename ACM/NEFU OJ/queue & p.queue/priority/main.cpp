#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,x1;
        cin>>x;
        if(x==1){
            cin>>x1;
            q.push(x1);
        }
        if(x==2&&!q.empty()){
            cout<<q.top()<<endl;
        }
        if(x==3&&!q.empty()){
            q.pop();
        }
    }
    return 0;
}
