#include <bits/stdc++.h>

using namespace std;
queue<int>q;
set<int>s;
set<int>::iterator it;
int main()
{
    int n,k,p;
    cin>>n>>k>>p;
    for(int i=1;i<=k;i++){
        q.push(i);
    }
    int num=0;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        num++;
        if(num%n==0)
            s.insert(tmp);
        for(int i=1;i<=p;i++){
            int tmp1=q.front();
            q.pop();
            q.push(tmp1);
        }
    }
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
    return 0;
}
