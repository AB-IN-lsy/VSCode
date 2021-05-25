#include <bits/stdc++.h>
using namespace std;
queue<int>q;
int main()
{
    int n,m,num;
    while(cin>>n>>m){
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    num=0;
    while(q.size()>1){
        num++;
        int tmp=q.front();
        q.pop();
        if(num%m!=0)
            q.push(tmp);
    }
    cout<<q.front()<<endl;
    q.pop();
    }
    return 0;
}
