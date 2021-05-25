#include <bits/stdc++.h>

using namespace std;
queue<int>q;
int main()
{
    int n,num;
    cin>>n;
    while(n--){
            cin>>num;
        for(int i=1;i<=num;i++){
            q.push(i);
        }
        while(q.size()>1){
            cout<<q.front()<<",";
            q.pop();
            int tmp=q.front();
            q.pop();
            q.push(tmp);
        }
        cout<<endl;
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}
